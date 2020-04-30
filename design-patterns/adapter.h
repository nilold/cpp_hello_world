#include <utility>
#include <vector>
#include "string"

namespace nilolib{
    struct String{
        std::string m_string;

        String(const std::string& str){
            m_string = str;
        }

        size_t get_size() const{
            return m_string.size();
        }

        ArrayList<std::string> split(const std::string &delimiter=" ") const{

            auto output = std::make_unique<ArrayList<std::string>>(5);

            size_t last = 0;
            size_t next = 0;

            while((next = m_string.find(delimiter, last)) != std::string::npos){
                output->add(m_string.substr(last, next - last));
                last = next + 1;
            }

            return *output;
        }

    };
}