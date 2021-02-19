#include "amici/defines.h"
#include "amici/exception.h"
#include "amici/misc.h"

#include <gsl/gsl-lite.hpp>

#include <map>
#include <regex>
#include <vector>


namespace amici {

realtype getValueById(gsl::span<const char*> ids,
                      gsl::span<const realtype> values,
                      std::string const &id,
                      const char *id_name);

int setValueByIdRegex(gsl::span<const char*> ids,
                      gsl::span<realtype> values, realtype value,
                      std::string const &regex,
                      const char *id_name);

/**
 * @brief Array with unique IDs and names associated with its values
 *
 * Names and IDs are not owned and are read-only. This keep compilation time
 * and memory requirements low for large models.
 */
class NamedArray {
public:
    NamedArray(gsl::span<const char*> ids,
               gsl::span<const char*> names,
               std::vector<realtype> values)
        : ids_(ids), names_(names), values_(values)
    {
        Expects(ids_.size() == names_.size());
        Expects(values_.size() == names_.size());
    }

    /**
     * @brief Get value of first entry with the specified ID.
     * @param id ID
     * @return Value for the given ID
     */
    realtype getValueByID(std::string const &id) const {
        if (ids_.empty())
            throw AmiException(
                    "Cannot access values by ID as no IDs are set");

        return getValueById(ids_, values_, id, "id");

    }

    /**
     * @brief Get value of first entry with the specified name.
     * @param name Name
     * @return Value for the given name
     */
    realtype getValueByName(std::string const &name) const {
        if (names_.empty())
            throw AmiException(
                    "Cannot access values by name as no names are set");

        return getValueById(ids_, values_, name, "name");
    }

    /**
     * @brief Return index of the given ID
     * @param id ID to look up
     * @return Index of first match
     */
    int getIndexById(std::string id) const;

    /**
     * @brief Get names of all entries
     * @return Names
     */
    gsl::span<const char*> getNames() const
    {
        return names_;
    }

    /**
     * @brief Get IDs of all entries
     * @return IDs
     */
    gsl::span<const char*> getIDs() const
    {
        return ids_;
    }

    /**
     * @brief Get stored values.
     * @return Vector of values
     */
    std::vector<realtype> getValues() const {
        return values_;
    }

    /**
     * @brief Set the array values.
     * @param values Vector of values
     */
    void setValues(std::vector<realtype> const &values) {
        if (values.size() != ids_.size())
            throw AmiException(
                    "Number of provided values does not expected size.");
        values_ = values;
    };

    /**
     * @brief Set value for the specified ID.
     * @param id ID
     * @param value Value
     */
    void setValueByID(std::string const &id, realtype value) {
        auto it = std::find(ids_.begin(), ids_.end(), id);
        if (it != ids_.end()) {
            values_.at(it - ids_.begin()) = value;
        } else {
            throw AmiException("Could not find ID %s", id.c_str());
        }
    };

    /**
     * @brief Set values according IDs and mapped values.
     * @param values Map of IDs to values
     * @param ignoreErrors Ignore errors such as non-existant IDs
     */
    void setValueByID(const std::map<std::string, realtype> &values,
                      bool ignoreErrors) {
        for (auto& kv : values) {
            try {
                setValueByID(kv.first, kv.second);
            } catch (AmiException const&) {
                if(!ignoreErrors)
                    throw;
            }
        }
    }

    /**
     * @brief Set value for the specified name.
     * @param name Name
     * @param value Value
     */
    void setValueByName(std::string const &id, realtype value)
    {
        auto it = std::find(names_.begin(), names_.end(), id);
        if (it != names_.end()) {
            values_.at(it - names_.begin()) = value;
        } else {
            throw AmiException("Could not find name %s", id.c_str());
        }
    }

    /**
     * @brief Set values according namess and mapped values.
     * @param values Map of names to values
     * @param ignoreErrors Ignore errors such as non-existant names
     */
    void setValueByName(const std::map<std::string, realtype> &values,
                        bool ignoreErrors)
    {
        for (auto& kv : values) {
            try {
                setValueByName(kv.first, kv.second);
            } catch (AmiException const&) {
                if(!ignoreErrors)
                    throw;
            }
        }
    }

    /**
     * @brief Set all entries with IDs matching the specified regex to the given
     * value.
     * @param id_regex ID regex
     * @param value New value
     * @return Number of matching IDs
     */
    int setValueByIDRegex(std::string const &id_regex, realtype value) {
        if (ids_.empty())
            throw AmiException(
                    "Cannot access values by ID as no IDs are set");
        return setValueByIdRegex(ids_, values_, value, id_regex, "id");
    };

    /**
     * @brief Set all entries with names matching the specified regex to the
     * given value.
     * @param name_regex Name regex
     * @param value New value
     * @return Number of matching names
     */
    int setValueByNameRegex(std::string const &name_regex, realtype value) {
        if (names_.empty())
            throw AmiException(
                    "Cannot access values by name as no names are set");
        return setValueByIdRegex(names_, values_, value, name_regex, "name");

    };

private:
    gsl::span<const char*> ids_;
    gsl::span<const char*> names_;
    std::vector<realtype> values_;
};



/**
 * @brief Local helper function to set values via regex
 * @param ids names/ids to search
 * @param values values to be updated
 * @param value target value
 * @param regex string according to which names/ids are to be matched
 * @param id_name string indicating whether name or id was specified
 * @return number of matched names/ids
 */
int setValueByIdRegex(gsl::span<const char*> ids,
                      gsl::span<realtype> values, realtype value,
                      std::string const &regex,
                      const char *id_name) {
    try {
        std::regex pattern(regex);
        int n_found = 0;
        for (const auto &id : ids) {
            if (std::regex_match(id, pattern)) {
                values.at(&id - &ids[0]) = value;
                ++n_found;
            }
        }

        if (n_found == 0)
            throw AmiException("Could not find any %s matching pattern (%s)",
                               id_name, regex.c_str());

        return n_found;
    } catch (std::regex_error const &e) {
        auto err_string = regexErrorToString(e.code());
        throw AmiException("Specified regex pattern %s could not be compiled:"
                           " %s (%s)", regex.c_str(), e.what(),
                           err_string.c_str());
    }
}


/**
 * @brief Local helper function to get parameters
 * @param ids names/ids to match
 * @param values values to return
 * @param id name/id to look for in ids
 * @param variable_name string indicating what variable we are looking at
 * @param id_name string indicating whether name or id was specified
 * @return value of the selected entry
 */
realtype getValueById(gsl::span<const char*> ids,
                      gsl::span<const realtype> values,
                      std::string const &id,
                      const char *id_name) {
    auto it = std::find(ids.begin(), ids.end(), id);
    if (it != ids.end())
        return values.at(it - ids.begin());

    throw AmiException("Could not find any entry with %s %s", id_name, id.c_str());
}


} // namespace amici
