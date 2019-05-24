#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        map<string,vector<string>> container ;
        for ( string file : paths ) {
            string directoryPath = file.substr ( 0 , file.find ( ' ' ) );
            file = file.substr ( file.find(' ')+1 );
            vector<pair<string,string>> fileContents;
            auto spaceLoc = file.find ( ' ' );
            while ( spaceLoc != string::npos ) {
                auto bracPos = file.find ( '(' );
                string fileName = file.substr ( 0 , bracPos );
                string fileContent = file.substr ( bracPos+1 , spaceLoc-2-bracPos );
                pair<string,string> currentFile = make_pair ( fileName, fileContent );
                fileContents.push_back ( currentFile );
                file = file.substr ( spaceLoc+1 );
                spaceLoc = file.find ( ' ' );
            }
            string lastFileName = file.substr ( 0 , file.find ( '(' ) ) , 
                lastFileContent = file.substr ( file.find('(')+1 , file.size()-2-file.find('(' ) );
            fileContents.push_back  ( {lastFileName , lastFileContent } );
            for ( auto fileValue : fileContents ) 
                container[fileValue.second].push_back ( directoryPath + "/" + fileValue.first );
        }
        vector<vector<string>> answer ;
        for ( auto dups : container )  
            if ( dups.second.size() > 1 ) {
                vector<string> temp ;
                for ( auto file : dups.second ) temp.push_back ( file );
                answer.push_back ( temp );
            }
        return answer;
    }
};