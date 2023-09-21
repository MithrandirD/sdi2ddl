#ifndef UTILS_H
#define UTILS_H

using namespace std;
/** escape a string
@param[in]	    text	  string to escape
@return escaped string */
string scape_string(const string &text) {
  string ret = "`";
  ret.append(text);
  ret.append("`");
  return ret;
}


/** get gipk value from a string
@param[in]	text	string to parse
@return the bool value */
bool get_gipk_value(const std::string& str) {
    std::size_t pos = str.find("gipk=");
    if (pos == std::string::npos) {
        // Not found
        return false; 
    }

    std::size_t start = pos + 5; 
    std::size_t end = str.find(';', start);
    if (end == std::string::npos) {
        end = str.length();
    }

    std::string valueStr = str.substr(start, end - start);
    int value = std::stoi(valueStr); // convert to integer

    return value != 0; 
}

#endif /* UTILS_H */
