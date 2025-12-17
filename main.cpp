#include <iostream>
#include <fstream>
#include <unordered_map>
using namespace std;

// converting string to lowercase (for case-insensitive choice)
string toLower(string s) {
    int len=s.length();
    for (int i=0;i<len;i++) {
        if (s[i]>='A' && s[i]<='Z') {
            s[i]=s[i]+32;
        }
    }
    return s;
}
//preparing a statistics for our input file
void Show_statistics(unordered_map<string,int>&wordcount) {
    int totalWords = 0;
    string longestWord = "";

    //going through each word in the map
    for (const auto&entry :wordcount) {
        string word=entry.first;
        int freq=entry.second;
        //counted total words in our file
        totalWords+=freq;
        //condition to find out the longest word in our file
        if (word.length()>longestWord.length()) {
            longestWord = word;
        }
    }
    //finding overall average word length in our file
    double avgWordLength = 0;
    if (totalWords != 0 && wordcount.size()!= 0) {
        int sumLengths = 0;
        for (const auto &entry:wordcount) {
            sumLengths+=entry.first.length();
        }
        avgWordLength=(double)sumLengths/wordcount.size();
    }

    cout<<"   FILE STATISTICS\n";
    cout<<"----------------------\n";
    cout<<"Total words        : "<<totalWords<<endl;
    cout<<"Unique words       : "<<wordcount.size()<<endl;
    cout<<"Longest word       : "<<longestWord<<endl;
    cout<<"Average word length: "<<avgWordLength<< endl;
}
/*taking alphabets, digits and meaningful special characters
     in consideration*/
string Clean_Word(string s) {
    string result="";
    for (char c :s) {
        if ((c>='a' && c<='z') ||(c>='A' && c<='Z') ||
            (c>='0' && c<='9') || c=='+'|| c=='-' || c=='_' ||
            c=='.'|| c=='\'')
         {
            result += c;
        }
    }
    return result;
}

int main(){
     //opening the file
    ifstream fin("sample.txt");
    if (!fin) {
        cout << "Error: File not found!"<<endl;
        return 0;
    }
  
//Mapping the words of the file to their frequency of occurrence
    unordered_map<string,int>frequency_dict;    
    string word;
    //reading and storing the words
    while (fin>>word) {
        word=Clean_Word(word);
        if(word!=""){
            frequency_dict[word]++;
        }
    }
    fin.close();
    /*user will be given a choice to either view the file 
    statistics or search the desired word*/
    int main_choice;
    cout<<"      WELCOME"<<endl;
    cout<<"1.Search a Word "<<endl;
    cout<<"2.View file statistics"<<endl;
    cin>>main_choice;

    if(main_choice==1){
        int search_mode;
        cout<<"Choose your search mode :"<<endl;
        cout<<"1.Case-Insensitive"<<endl;
        cout<<"2.Case-Sensitive"<<endl;
        cout<<"Enter Choice: ";
        cin>>search_mode;

        string search;
        cout<<"Enter the word you want to seacrh";
        cin>>search;
        search=Clean_Word(search);
        
        if(search_mode==1){
            search=toLower(search);

            int count=0;
            for(auto entry : frequency_dict){
                if(toLower(entry.first)==search){
                    count+=entry.second;
                }
            }
            cout<<"Count : "<<count<<" times"<<endl;
        }
        else {
            cout<<"Count : "<<frequency_dict[search]<<" times"<<endl;
        }
    }
    else if( main_choice==2){
        Show_statistics(frequency_dict);
    }
    else{
        cout<<"INVALID Choice!"<<endl;
    }
    return 0;  }
