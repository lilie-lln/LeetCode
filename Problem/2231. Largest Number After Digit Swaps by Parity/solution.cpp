class Solution {
public:
    int largestInteger(int num) {
        string s = to_string(num);

        for(int i=0; i<s.size(); i++){
            int digit = s[i] - '0';
            int index = i;
            for(int j=i+1; j<s.size(); j++){
                int number = s[j] - '0';
                if(number > digit && digit % 2 == number % 2){
                    digit = number;                        
                    index = j;
                }
            }
                swap(s[index], s[i]);
        }
        num = stoi(s);
        return num;
    }
};
