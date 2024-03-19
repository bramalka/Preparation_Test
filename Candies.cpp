#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

long candies(int n, vector<int> arr) {
    long ans = 0;    
    vector<int> v(n, 1);
    vector<int> v1(n, 1);
    
    for(int i = 0; i < n; i++){        
        if(arr[i] > arr[i - 1]){
            v[i] = v[i - 1] + 1;
        }
        cout << arr[i] << " ";
        cout << v[i] << endl;
    }
    
    cout << endl;
    
    for(int i = n - 1; i >= 0; i--){        
        if(arr[i] > arr[i + 1]){
            v1[i] = v1[i + 1] + 1;
        }
        cout << arr[i] << " ";
        cout << v1[i] << endl;
    }
    
    for(int i = 0; i < n; i++){
        ans += max({v1[i],v[i]});
    }
    
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        string arr_item_temp;
        getline(cin, arr_item_temp);

        int arr_item = stoi(ltrim(rtrim(arr_item_temp)));

        arr[i] = arr_item;
    }

    long result = candies(n, arr);

    fout << result << "\n";

    fout.close();

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
