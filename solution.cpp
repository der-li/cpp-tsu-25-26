#include <string>
#include <iostream>
using namespace std;
int main(){
    string buffer;
    cin >> buffer;
    cin >> buffer;
    cin >> buffer;
    
    int n;
    cin >> n;
    
    int product = 0;
    int sum = 0;
    
    for(int q=0;q<n;q++){
    int number;
    int price;
    string word;
    
    while(word != "за" and word != "по"){
        cin >> word;
    }
    if(word == "за"){
        number = 1;
        cin >> price;
        cin >> word;
    }else{
        cin >> price;
        cin >> word;
        cin >> number;
        cin >> word;
    }
    sum += number*price;
    product += number;
    }
    if(product == 1){
        cout<<"Куплен товар за "<<sum<<" рублей"<<endl;
    }else{
        cout<<"Куплено "<<product <<" штук товара за "<<sum<<" рублей"<<endl;
    }
    return 0;
}
