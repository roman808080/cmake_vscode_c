#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);



/*
 * Complete the 'print_classification' function below.
 *
 * The function accepts 2D_INTEGER_ARRAY raw_data as parameter.
 */

void print_classification(vector<vector<int>> raw_data) {

}

int main()
{
    string raw_data_rows_temp;
    getline(cin, raw_data_rows_temp);

    int raw_data_rows = stoi(ltrim(rtrim(raw_data_rows_temp)));

    string raw_data_columns_temp;
    getline(cin, raw_data_columns_temp);

    int raw_data_columns = stoi(ltrim(rtrim(raw_data_columns_temp)));

    vector<vector<int>> raw_data(raw_data_rows);

    for (int i = 0; i < raw_data_rows; i++) {
        raw_data[i].resize(raw_data_columns);

        string raw_data_row_temp_temp;
        getline(cin, raw_data_row_temp_temp);

        vector<string> raw_data_row_temp = split(rtrim(raw_data_row_temp_temp));

        for (int j = 0; j < raw_data_columns; j++) {
            int raw_data_row_item = stoi(raw_data_row_temp[j]);

            raw_data[i][j] = raw_data_row_item;
        }
    }

    print_classification(raw_data);

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
