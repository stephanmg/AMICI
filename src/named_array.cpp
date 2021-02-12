#include "amici/named_array.h"

#include "amici/misc.h"

#include <regex>

namespace amici {


/**
 * @brief Local helper function to set values via regex
 * @param ids names/ids to search
 * @param values values to be updated
 * @param value target value
 * @param regex string according to which names/ids are to be matched
 * @param id_name string indicating whether name or id was specified
 * @return number of matched names/ids
 */
static int setValueByIdRegex(gsl::span<const char*> ids,
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
static realtype getValueById(gsl::span<const char*> ids,
                             gsl::span<const realtype> values,
                             std::string const &id,
                             const char *id_name) {
    auto it = std::find(ids.begin(), ids.end(), id);
    if (it != ids.end())
        return values.at(it - ids.begin());

    throw AmiException("Could not find any entry with %s %s", id_name, id.c_str());
}

NamedArray::NamedArray(
        gsl::span<const char *> ids,
        gsl::span<const char *> names,
        std::vector<realtype> values)
    : ids_(ids), names_(names), values_(values)
{
    Expects(ids_.size() == names_.size());
    Expects(values_.size() == names_.size());
}

realtype NamedArray::getValueByID(const std::string &id) const {
    if (ids_.empty())
        throw AmiException(
            "Cannot access values by ID as no IDs are set");

    return getValueById(ids_, values_, id, "id");

}

realtype NamedArray::getValueByName(const std::string &name) const {
    if (names_.empty())
        throw AmiException(
            "Cannot access values by name as no names are set");

    return getValueById(ids_, values_, name, "name");
}

gsl::span<const char *> NamedArray::getNames() const
{
    return names_;
}

gsl::span<const char *> NamedArray::getIDs() const
{
    return ids_;
}

std::vector<realtype> NamedArray::getValues() const {
    return values_;
}

void NamedArray::setValues(const std::vector<realtype> &values) {
    if (values.size() != ids_.size())
        throw AmiException(
                "Number of provided values does not expected size.");
    values_ = values;
}

void NamedArray::setValueByID(const std::string &id, realtype value) {
    auto it = std::find(ids_.begin(), ids_.end(), id);
    if (it != ids_.end()) {
        values_.at(it - ids_.begin()) = value;
    } else {
        throw AmiException("Could not find ID %s", id.c_str());
    }
}

void NamedArray::setValueByID(const std::map<std::string, realtype> &values, bool ignoreErrors) {
    for (auto& kv : values) {
        try {
            setValueByID(kv.first, kv.second);
        } catch (AmiException const&) {
            if(!ignoreErrors)
                throw;
        }
    }
}

void NamedArray::setValueByName(const std::string &id, realtype value)
{
    auto it = std::find(names_.begin(), names_.end(), id);
    if (it != names_.end()) {
        values_.at(it - names_.begin()) = value;
    } else {
        throw AmiException("Could not find name %s", id.c_str());
    }
}

void NamedArray::setValueByName(const std::map<std::string, realtype> &values, bool ignoreErrors)
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

int NamedArray::setValueByIDRegex(const std::string &id_regex, realtype value) {
    if (ids_.empty())
        throw AmiException(
            "Cannot access values by ID as no IDs are set");
    return setValueByIdRegex(ids_, values_, value, id_regex, "id");
}

int NamedArray::setValueByNameRegex(const std::string &name_regex, realtype value) {
    if (names_.empty())
        throw AmiException(
            "Cannot access values by name as no names are set");
    return setValueByIdRegex(names_, values_, value, name_regex, "name");

}



} // namespace amici
