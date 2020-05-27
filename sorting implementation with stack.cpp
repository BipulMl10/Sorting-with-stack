#include <iostream>
#include <stack>
#include <vector>
/*
Serarch_tag
Fixed_code
*/



using namespace std;


bool isSingleDigit(int num){
    return num/10 == 0;
}

bool isDoubleDigit(int num){
    return (num/10 <= 9 && num/10 > 0);
}

int main(){
    int N;
    cin >> N;
    stack<int> s1;
    stack<int> s2;
    for(int i=0;i<N;i++){
        int num;
        cin >> num;
        s1.push(num);
    }  
    while(!s1.empty()){
   
    //Fixed_code
      /*  if(s2.empty() || s2.top() < s1.top()){
            int num = s1.top();
            s1.pop();
            s2.push(num);
        }*/
     //Fixed_code only if s2.empty for othere case we have to check other cases as well like mod = 1
     //signle or double digit if s1 is isDoubleDigit and s2 isSingleDigit then also s2<s1 but we have to
     //check others cases as well
        int flag = 0;
        if(s2.empty())
        {
            flag=1;
            int num = s1.top();
            s1.pop();
            s2.push(num);
        }
        //Fixed_code end
        else{
            int num1 = s1.top();
            int num2 = s2.top();

            flag = 0;

            if(isSingleDigit(num1) && isSingleDigit(num2))
            {
                if(abs(num1-num2) == 1)
                {
                    flag = 1;
                    s1.pop();
                    s2.pop();
                    int maxi = max(num1*10 + num2, num2*10 + num1);
                    s2.push(maxi);
                }
                //Fixed_code if mod is not satisfied the we need to chcek weather num1 > num2
                //this condtion was not checked leading to alignite loop
                else if(num2 < num1)
                {
                    s1.pop();
                    s2.push(num1);
                }
                //Fixed_code end
               
            }
            else if(isSingleDigit(num1) && isDoubleDigit(num2))
            {
                int x = num1;
                int a = num2/10;
                int b = num2%10;

                if(abs(a-x) == 1 || abs(b-x) == 1){
                    flag = 1;
                    s1.pop();
                    s2.pop();
                    int maxi = max(x, max(a,b));
                    int mini = min(x, min(a,b));
                    int n = maxi*10 + mini;
                    s2.push(n);
                }
                else if(x > a)
                {
                    flag = 1;
                    s1.pop();
                    s2.push(x);
                }
            }
            else if(isDoubleDigit(num1) && isSingleDigit(num2))
            {
                int a = num1/10;
                int b = num1%10;
                int x = num2;
                if(abs(a-x) == 1 || abs(b-x) == 1){
                    flag = 1;
                    s1.pop();
                    s2.pop();
                    int maxi = max(x, max(a,b));
                    int mini = min(x, min(a,b));
                    int n = maxi*10 + mini;
                    s2.push(n);
                }
                //Fixed_code this and also s1 being two digit it will be always greater the s2 as
                //it is a signle digit number
                s1.pop();
        s2.push(num1);
        flag = 1;
                //Fixed_code end
            }
            else if(isDoubleDigit(num1) && isDoubleDigit(num2))
            {
                int a = num1/10;
                int b = num1%10;

                int c = num2/10;
                int d = num2%10;
                if(abs(a-d) == 1 || abs(b-c) == 1){
                    flag = 1;
                    s1.pop();
                    s2.pop();
                    int maxi = max(a, max(b, max(c,d)));
                    int mini = min(a, min(b, min(c,d)));
                    int n = maxi*10 + mini;
                    s2.push(n);
                }
               
                //Fixed_code if num2 is smaller and their differnce is not eqully to 1
                //then we need to pop from s1 and push into s2 as it can lead to infinite  loop
                else
                {
                   flag = 1;
               s2.push(s1.top());
               s1.pop();
                }
                //Fixed_code end
            }
            if((num2 > num1) && (flag == 0))
            {
                s1.pop();
                int temp = num1;

                s1.push(s2.top());
                s2.pop();

                s1.push(temp);
            }
        }
    }

    vector<int> ans;

    while(!s2.empty()){
        int num = s2.top();
        s2.pop();

        cout << num << " ";

        if(isSingleDigit(num)){
            ans.push_back(num);
        }
        else if(isDoubleDigit(num)){
            int maxi = num/10;
            int mini = num%10;

            for(int i=maxi;i>=mini;i--){
                ans.push_back(i);
            }
        }

       
    }
    cout << endl;

    for(int i=0;i<ans.size();i++){
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}
