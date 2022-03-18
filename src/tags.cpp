#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

namespace
{
    void read_hrml(std::vector<string> &hrml, const int number_of_strings)
    {
        for (int i = 0; i < number_of_strings; ++i)
        {
            std::string line("");
            std::getline(std::cin, line);
            hrml.push_back(line);
        }
    }

    void read_queries(std::vector<string> &queries, const int number_of_queries)
    {
        for (int i = 0; i < number_of_queries; ++i)
        {
            std::string line("");
            std::getline(cin, line);
            queries.push_back(line);
        }
    }

    void print_pair(const std::string &key, const std::string &value)
    {
        std::cout << "Key = " << key << ", value = " << value << std::endl;
    }

    void print_map_elements(const std::map<string, string> &map_of_hrml)
    {
        for (const auto &[key, value] : map_of_hrml)
        {
            print_pair(key, value);
        }
    }

    void print_element(std::map<string, string> &map_of_hrml, const std::string &key)
    {
        print_pair(key, map_of_hrml[key]);
    }

}

int main()
{
    int number_of_lines = 0;
    int number_of_queries = 0;

    cin >> number_of_lines >> number_of_queries;
    cin.ignore();

    std::vector<string> hrml;
    std::vector<string> queries;

    read_hrml(hrml, number_of_lines);
    read_queries(queries, number_of_queries);

    std::map<string, string> m;
    std::vector<string> tag;

    for (const auto &line : hrml)
    {
        std::string temp = line;
        temp.erase(remove(temp.begin(), temp.end(), '\"'), temp.end());
        temp.erase(remove(temp.begin(), temp.end(), '>'), temp.end());

        if (temp.substr(0, 2) == "</")
        {
            tag.pop_back();
        }
        else
        {
            stringstream ss;
            ss.str("");
            ss << temp;
            string t1, p1, v1;
            char ch;
            ss >> ch >> t1 >> p1 >> ch >> v1;
            string temp1 = "";
            if (tag.size() > 0)
            {
                temp1 = *tag.rbegin();
                temp1 = temp1 + "." + t1;
            }
            else
            {
                temp1 = t1;
            }

            tag.push_back(temp1);

            auto key = *tag.rbegin() + "~" + p1;
            m[key] = v1;

            while (ss)
            {
                p1 = "";
                v1 = "";

                ss >> p1 >> ch >> v1;
                if (p1 != "")
                {
                    key = *tag.rbegin() + "~" + p1;
                    m[key] = v1;
                }
            }
        }
    }

    for (const auto &query_line : queries)
    {
        if (m.find(query_line) == m.end())
        {
            cout << "Not Found!\n";
        }
        else
        {
            cout << m[query_line] << endl;
        }
    }

    print_map_elements(m);

    return 0;
}