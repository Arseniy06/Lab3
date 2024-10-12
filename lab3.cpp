#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <string>
using namespace std;

template<class T>
std::vector<T> generate_random_vector(std::size_t num, T min = -10, T max = 10)
{
    std::random_device rd;
    std::mt19937 e2(rd());
    std::uniform_real_distribution<> dist(min, max);

    auto lambda = [&e2, &dist] () -> T { return dist(e2); };

    std::vector<T> result(num);
    std::generate_n(result.begin(), num, lambda);
    return result;
}


int main() {
    int task;
    int size = 10;
    cin>>task;
    if (task == 1) {
        vector<int> default_array = generate_random_vector<int>(size, 1, 50);
        int doubled[size] = {0};
        for (int i = 0; i < size; ++i) {
            doubled[i] = default_array[i] * 2;
        }
        for (int i = 0; i < size; ++i) {
            cout << default_array[i] << " ";
        }
        cout << endl;
        for (int i = 0; i < size; ++i) {
            cout << doubled[i] << " ";
        }
        cout << endl;
        int a;
        cin >> a;
        int aed[size] = {0};
        for (int i = 0; i < size; ++i) {
            aed[i] = default_array[i] - a;
        }
        for (int i = 0; i < size; ++i) {
            cout << aed[i] << " ";
        }
        cout << endl;
    } else if (task == 2) {
        vector<int> default_array = generate_random_vector<int>(size, 1, 50);
        int sum = 0;
        int sumsq = 0;
        int sum6 = 0;
        int rangesum = 0;
        int avg = 0;
        int rangeavg = 0;
        for (int i = 0; i < size; ++i) {
            cout << default_array[i] << " ";
        }
        cout << endl;
        for (int i = 0; i < size; ++i) {
            sum += default_array[i];
            sumsq += default_array[i] * default_array[i];
        }
        for (int i = 0; i < 6; ++i) {
            sum6 += default_array[i];
        }
        int k1;
        int k2;
        cin >> k1;
        cin >> k2;
        for (int i = k1 - 1; i < k2; ++i) {
            rangesum += default_array[i];
        }
        avg = sum / size;
        int s1;
        int s2;
        int tmpsum = 0;
        cin >> s1;
        cin >> s2;
        for (int i = s1 - 1; i < s2; ++i) {
            tmpsum += default_array[i];
        }
        rangeavg = tmpsum / (s2 - s1 + 1);
        cout << sum << " " << sumsq << " " << sum6 << " " << rangesum << " " << avg << " " << rangeavg << endl;
    } else if (task == 3) {
        vector<int> default_array = generate_random_vector<int>(20, 1, 50);
        int moved[20] = {0};
        moved[0] = default_array[17];
        moved[1] = default_array[18];
        moved[2] = default_array[19];
        for (int i = 3; i < 17; ++i) {
            moved[i] = default_array[i];
        }
        moved[17] = default_array[0];
        moved[18] = default_array[1];
        moved[19] = default_array[2];
        for (int i = 0; i < 20; ++i) {
            cout << default_array[i] << " ";
        }
        cout << endl;
        for (int i = 0; i < 20; ++i) {
            cout << moved[i] << " ";
        }
        cout << endl;
    } else if (task == 4){
        vector<int> default_array = generate_random_vector<int>(size, -50, 50);
        int noneg[size-1] = {};
        int noeven[size-1] = {};
        int firstneg = -1;
        int lasteven = -1;
        for(int i = 0; i<size; ++i){
            if (default_array[i]<0)
            {
                firstneg = i;
                break;
            }
        }
        for (int i = size; i>0; --i){
            if ((default_array[i])%2==0){
                lasteven = i;
                break;
            }
        }
        if (firstneg!=-1 and firstneg != 0 and firstneg !=size-1) {
            for (int i = 0; i < firstneg - 1; ++i) {
                noneg[i] = default_array[i];
            }
            for (int i = firstneg + 1; i < size; ++i) {
                noneg[i - 1] = default_array[i];
            }
        } else if (firstneg!=-1 and firstneg == 0){
            for(int i = 1; i<size;++i) {
                noneg[i - 1] = default_array[i];
            }
        } else if (firstneg!=-1 and firstneg==size-1){
            for(int i = 0; i<size-1;++i){
                noneg[i]=default_array[i];
            }
        }
        if (lasteven!=-1 and lasteven != 0 and lasteven !=size-1) {
            for (int i = 0; i < lasteven - 1; ++i) {
                noeven[i] = default_array[i];
            }
            for (int i = lasteven + 1; i < size; ++i) {
                noeven[i - 1] = default_array[i];
            }
        } else if (lasteven!=-1 and lasteven == 0){
            for(int i = 1; i<size;++i) {
                noeven[i - 1] = default_array[i];
            }
        } else if (lasteven!=-1 and lasteven==size-1){
            for(int i = 0; i<size-1;++i){
                noeven[i]=default_array[i];
            }
        }
        for (int i = 0; i < size; ++i) {
            cout << default_array[i] << " ";
        }
        cout << endl;
        for (int i = 0; i < size-1; ++i) {
            cout << noneg[i] << " ";
        }
        cout << endl;
        for (int i = 0; i < size-1; ++i) {
            cout << noeven[i] << " ";
        }
        cout << endl;
    } else if (task == 5){
        string city;
        cin>>city;
        if (city.length()%2==0){
            cout<<"Длина строки - чётное число"<<endl;
        } else{
            cout<<"Длина строки - нечётное число"<<endl;
        }
    } else if (task == 6){
        string surn1;
        string surn2;
        cin>>surn1;
        cin>>surn2;
        if (surn1.length()>surn2.length()){
            cout<<"Первая строка длиннее"<<endl;
        } else if (surn1.length()==surn2.length()){
            cout<<"Длины строк равны"<<endl;
        } else{
            cout<<"Вторая строка длиннее"<<endl;
        }
    } else if (task == 7){
        string city1;
        string city2;
        string city3;
        cin>>city1;
        cin>>city2;
        cin>>city3;
        int len1 = city1.length();
        int len2 = city2.length();
        int len3 = city3.length();
        string cities[3] = {city1,city2,city3};
        int lengths[3] = {len1,len2,len3};
        int malen = 0;
        int milen = 999;
        for (int i = 0; i<3;++i){
            malen = max(malen, lengths[i]);
            milen = min(milen, lengths[i]);
        }
        for (int i = 0; i<3; ++i){
            if (lengths[i]==malen){
                cout<<"Самая длинная строка: "<<cities[i]<<endl;
            }
            if (lengths[i]==milen){
                cout<<"Самая короткая строка: "<<cities[i]<<endl;
            }
        }
    } else if (task == 8){
        string str;
        int m;
        int n;
        cin>>str;
        cin>>m;
        cin>>n;
        for (int i = m-1; i<n;++i){
            cout<<str[i];
        }
        cout<<endl;
    } else if (task == 9){
        string str;
        cin>>str;
        for(int i = 0; i<str.length();++i){
            cout<<"*";
        }
        cout<<str;
        for(int i = 0; i<str.length();++i){
            cout<<"*";
        }
    } else if (task == 10) {
        string str;
        cin >> str;
        float acount = 0;
        char a = 'a';
        for (int i = 0; i < str.length(); ++i) {
            if ((str[i]) == a) {
                acount++;
            }
        }
        cout << acount / str.length() * 100 << "%" << endl;
    } else if (task == 11){
        string def_sent = "Can you can a can as a canner can can a can?";
        string newWord;
        cin>>newWord;
        cout<<newWord<<" you "<<newWord<<" a "<<newWord<<" as a "<<newWord<<"nner "<<newWord<<" "<<newWord<<" a "<<newWord<<"?"<<endl;
    }
    return 0;
}
