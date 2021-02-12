#include <gsl/gsl-lite.hpp>
#include "amici/defines.h"
#include "amici/exception.h"
#include <vector>
#include <map>


namespace amici {

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
               std::vector<realtype> values);

    /**
     * @brief Get value of first entry with the specified ID.
     * @param id ID
     * @return Value for the given ID
     */
    realtype getValueByID(std::string const &id) const;

    /**
     * @brief Get value of first entry with the specified name.
     * @param name Name
     * @return Value for the given name
     */
    realtype getValueByName(std::string const &name) const;

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
    gsl::span<const char*> getNames() const;

    /**
     * @brief Get IDs of all entries
     * @return IDs
     */
    gsl::span<const char*> getIDs() const;

    /**
     * @brief Get stored values.
     * @return Vector of values
     */
    std::vector<realtype> getValues() const;

    /**
     * @brief Set the array values.
     * @param values Vector of values
     */
    void setValues(std::vector<realtype> const &values);;

    /**
     * @brief Set value for the specified ID.
     * @param id ID
     * @param value Value
     */
    void setValueByID(std::string const &id, realtype value);;

    /**
     * @brief Set values according IDs and mapped values.
     * @param values Map of IDs to values
     * @param ignoreErrors Ignore errors such as non-existant IDs
     */
    void setValueByID(const std::map<std::string, realtype> &values,
                      bool ignoreErrors);

    /**
     * @brief Set value for the specified name.
     * @param name Name
     * @param value Value
     */
    void setValueByName(std::string const &id, realtype value);

    /**
     * @brief Set values according namess and mapped values.
     * @param values Map of names to values
     * @param ignoreErrors Ignore errors such as non-existant names
     */
    void setValueByName(const std::map<std::string, realtype> &values,
                        bool ignoreErrors);

    /**
     * @brief Set all entries with IDs matching the specified regex to the given
     * value.
     * @param id_regex ID regex
     * @param value New value
     * @return Number of matching IDs
     */
    int setValueByIDRegex(std::string const &id_regex, realtype value);;

    /**
     * @brief Set all entries with names matching the specified regex to the
     * given value.
     * @param name_regex Name regex
     * @param value New value
     * @return Number of matching names
     */
    int setValueByNameRegex(std::string const &name_regex, realtype value);;

private:
    gsl::span<const char*> ids_;
    gsl::span<const char*> names_;
    std::vector<realtype> values_;
};


} // namespace amici
