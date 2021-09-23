#include <iostream>
#include <string>
int index_appear(std::string* arr, int length, std::string str) {
    int i;
    for (i = 0; i < length; i++)
        if (arr[i] == str)
            return i;
    return -1;
}
void add_arr_string(std::string** arr, int* len, std::string word) {
    std::string* n = new std::string[(*len) + 1];
    int i;
    for (i = 0; i < *len; i++)
        n[i] = (*arr)[i];
    n[i] = word;
    delete[](*arr);
    (*arr) = n;
    (*len)++;
}
std::string encoder(const std::string& data)
{
    std::string* arr = NULL;
    std::string res = "";
    std::string temp = "";
    int i, len = 0, index, r;
    for (i = 0; i < data.length();) {
        temp = "";
        index = -1;
        r = -1;
        do {
            index = r;
            temp += data[i++];
            r = index_appear(arr, len, temp);
        } while (i < data.length() && r != -1);
        if (r == -1) {
            res += std::to_string(index + 1) + "" + temp[temp.length() - 1];
            add_arr_string(&arr, &len, temp);
        }
        else {
            res += std::to_string(r + 1) + "";
        }
    }
    delete[]arr;
    return res;
}

std::string decoder(const std::string& data)
{
    std::string* arr = NULL;
    std::string res = "";
    int i, len = 0, is_last = 0, r = 0;
    add_arr_string(&arr, &len, "");
    std::string index;
    for (i = 0; i < data.length(); i++)
        if (data[i] >= '0' && data[i] <= '9') {
            r = 1;
            break;
        }
    if (r == 0)
        return data;
    for (i = 0; i < data.length();) {
        index = "";
        is_last = 0;
        while (i < data.length() && data[i] >= '0' && data[i] <= '9')
            index += data[i++];
        if (i < data.length()) {
            add_arr_string(&arr, &len, arr[stoi(index)] + data[i]);
            is_last = 1;
        }
        i++;
    }
    for (i = 0; i < len; i++)
        res += arr[i];
    if (is_last == 0)
        res += arr[stoi(index)];
    return res;
}
int main()
{   
    int i;
    do{
        std::cout << "Ecode 1\nDecode 2\nOther exit\n";
        std::cin >> i;
        std::cin.ignore();
        std::string text = "";
        switch (i) {
            case 1:
                std::cout << "Enter text\n";
                std::getline(std::cin,text);
                std::cout << encoder(text)+"\n";
                break;
            case 2:
                std::cout << "Enter text\n";
                std::getline(std::cin, text);
                std::cout << decoder(text) + "\n";
                break;
        }
    } while (i >= 1 && i <= 2);
    std::cout << "Good Bye\n";
    system("pause");
}
