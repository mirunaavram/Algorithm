#include<bits/stdc++.h>
using namespace std;


int n,x;

int verify(vector<int> grades){
    int sum=0;
    for(int i=0;i<grades.size();i++){
        if(grades[i]>grades.size()-1)
            return 0;
        sum+=grades[i];
    }
    if(sum %2 == 1 )
        return 0;
    return 1;

}
string answer(vector<int> grades){

    if(verify(grades)){
        while(grades.size() != 0 ){
            sort(grades.begin(),grades.end(), greater<int>());
            int a=grades[0];
            grades.erase(grades.begin());
            for(int i=0;i<a;i++){
                if(grades[i]-1<0)
                    return "NU";
                else
                    grades[i]-=1;
            }
        }
        return "DA";
    }
    return "NU";
}

int main(){

    vector<int> grades;
    //int n = sizeof(grades) / sizeof(grades[0]);
    cin>>n;
for(int i=0;i<n;i++)
{
    cin>>x;
    grades.push_back(x);
}
    //n = sizeof(grades) / sizeof(grades[0]);
cout<<answer(grades);

}