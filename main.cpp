#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>


using namespace std;

ofstream outf("output.txt");
ifstream inf("input.txt");

void spliting(string str,vector<string>& sentences){
sentences.push_back(str);
    unsigned int splitAt;
    unsigned int splitLen = 1;
    string currentText;
    while (true)
    {
        currentText = sentences.back();
        splitAt = currentText.find('.');
        if(splitAt == string::npos)
        {
            // Break the loop and (implicitly) return.
            break;
        }
        sentences.back()=currentText.substr(0,splitAt);
        sentences.push_back(currentText.substr(splitAt+splitLen,currentText.size()-(splitAt+splitLen)));
    }
    if (sentences.back().empty()){sentences.erase(sentences.end());}

}



void upperCasting(vector<string>& sentences,string& word){
unsigned int foundAtPos;
vector<string> editedSentences;
    string editedword =word;
    transform(editedword.begin(),editedword.end(),editedword.begin(), ::toupper);
for (int i=0;i<sentences.size();i++){
    bool changesHappened=false;
    string currentSentence=sentences[i];
    foundAtPos=currentSentence.find(word);
    while (foundAtPos!= string::npos){
        currentSentence.replace(foundAtPos,editedword.size(),editedword);
        changesHappened=true;
        foundAtPos=currentSentence.find(word);
        }
    if (changesHappened){
        editedSentences.push_back(currentSentence);
    }
}
outf <<editedSentences.size()<<endl;
for (int i =0; i<editedSentences.size();i++){
    outf <<editedSentences[i]<<endl;
}

}
int main() {
string str;

getline (inf,str);

vector<string> outp;
spliting(str,outp);
int quantity;

inf >> quantity;
vector<string> words;
for (int i =0;i< quantity+1;i++){
    getline(inf,str);
    words.push_back(str);
}

words.erase(words.begin());

for (int i=0;i<words.size();i++) {
    upperCasting(outp, words[i]);
}
}
