#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

int count_invalid_boxes(vector<vector<string>> box_template_list);
int count_invalid_boxes_fast(vector<vector<string>> box_template_list);

/*
 * Complete the 'count_invalid_boxes' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts 2D_STRING_ARRAY box_template_list as parameter.
 */

int count_invalid_boxes(vector<vector<string>> box_template_list)
{
    int invalid = 0;

    for (const auto box : box_template_list)
    {
        map<char, int> elements = {};
        auto expected_box = box[0];

        for (auto character : expected_box)
        {
            auto search = elements.find(character);
            if (search != elements.end())
            {
                ++elements[character];
            }
            else
            {
                elements[character] = 1;
            }
        }

        auto reality_box = box[1];
        for (auto character : reality_box)
        {
            auto search = elements.find(character);
            if (search != elements.end())
            {
                --elements[character];
                if (elements[character] <= 0)
                {
                    elements.erase(character);
                }
            }
            else
            {
                ++invalid;

                elements.clear();
                break;
            }
        }

        if (elements.empty() != true)
        {
            ++invalid;
        }
    }
    return invalid;
}

int count_invalid_boxes_fast(vector<vector<string>> box_template_list)
{
    int invalid = 0;

    for (const auto box_pair : box_template_list)
    {
        // c, m, p
        int boxes_array[] = {0, 0, 0};

        for (const auto character : box_pair[0])
        {
            if (character == 'c')
            {
                ++boxes_array[0];
            }
            else if (character == 'm')
            {
                ++boxes_array[1];
            }
            else if (character == 'p')
            {
                ++boxes_array[2];
            }
            else
            {
                throw std::runtime_error("wrong type");
            }
        }

        for (const auto character : box_pair[1])
        {
            if (character == 'c')
            {
                --boxes_array[0];
            }
            else if (character == 'm')
            {
                --boxes_array[1];
            }
            else if (character == 'p')
            {
                --boxes_array[2];
            }
            else
            {
                throw std::runtime_error("wrong type");
            }
        }

        for(int i = 0; i < 3; ++i)
        {
            if (boxes_array[i] != 0)
            {
                ++invalid;
                break;
            }
        }
    }

    return invalid;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string box_template_list_rows_temp;
    getline(cin, box_template_list_rows_temp);

    int box_template_list_rows = stoi(ltrim(rtrim(box_template_list_rows_temp)));

    string box_template_list_columns_temp;
    getline(cin, box_template_list_columns_temp);

    int box_template_list_columns = stoi(ltrim(rtrim(box_template_list_columns_temp)));

    vector<vector<string>> box_template_list(box_template_list_rows);

    for (int i = 0; i < box_template_list_rows; i++)
    {
        box_template_list[i].resize(box_template_list_columns);

        string box_template_list_row_temp_temp;
        getline(cin, box_template_list_row_temp_temp);

        vector<string> box_template_list_row_temp = split(rtrim(box_template_list_row_temp_temp));

        for (int j = 0; j < box_template_list_columns; j++)
        {
            string box_template_list_row_item = box_template_list_row_temp[j];

            box_template_list[i][j] = box_template_list_row_item;
        }
    }

    int result = count_invalid_boxes_fast(box_template_list);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str)
{
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace))));

    return s;
}

string rtrim(const string &str)
{
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end());

    return s;
}

vector<string> split(const string &str)
{
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos)
    {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
