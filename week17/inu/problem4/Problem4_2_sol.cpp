#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

char low[] = { 'a','b','c','d','e','f','g' };

vector<string> split(string s, char delimeter) {
    vector<string> vs;
    stringstream input(s);
    string temp;

    while (getline(input, temp, delimeter))
        vs.push_back(temp);

    return vs;
}

int getPlaytime(string start, string end) {
    vector<string> sv = split(start, ':');
    vector<string> ev = split(end, ':');

    int s_minutes = stoi(sv[0]) * 60 + stoi(sv[1]);
    int e_minutes = stoi(ev[0]) * 60 + stoi(ev[1]);

    return e_minutes - s_minutes;
}

string replaceAkbo(string akbo) {
    string akbo_replace = "";

    for (char c : akbo) {
        if (c == '#') {
            char lowercase = low[akbo_replace.back() - 'A'];
            akbo_replace.pop_back();
            akbo_replace.push_back(lowercase);
        }
        else
            akbo_replace += c;
    }

    return akbo_replace;
}

string getAllAkbo(string akbo, int playtime) {
    string allAkbo = "";
    string akbo_replace = replaceAkbo(akbo);
    int akboLength = (int)akbo_replace.size();

    int iter = playtime / akboLength;
    if (iter == 0) {
        allAkbo = akbo_replace.substr(0, playtime);
    }
    else {
        for(int i = 0; i < iter; i++)
            allAkbo += akbo_replace;

        int remain = playtime % akboLength;
        allAkbo += akbo_replace.substr(0, remain);
    }

    return allAkbo;
}

string solution(string m, vector<string> musicinfos) {
    string answer = "";
    int max_playtime = 0;

    for (string musicinfo : musicinfos) {
        vector<string> info = split(musicinfo, ',');
        int playtime = getPlaytime(info[0], info[1]);
        string title = info[2];
        string allAkbo = getAllAkbo(info[3], playtime);

        m = replaceAkbo(m);
        if (allAkbo.find(m) != string::npos) {
            if (playtime > max_playtime) {
                max_playtime = playtime;
                answer = title;
            }
        }
    }
    return answer;
}

int main() {
    string m1 = "ABCDEFG";
    string m2 = "CC#BCC#BCC#BCC#B";
    string m3 = "ABC";
    string m4 = "CCB";
    vector<string> musicinfos1 = { "12:00,12:14,HELLO,CDEFGAB", "13:00,13:05,WORLD,ABCDEF" };
    vector<string> musicinfos2 = { "03:00,03:30,FOO,CC#B", "04:00,04:08,BAR,CC#BCC#BCC#B" };
    vector<string> musicinfos3 = { "12:00,12:14,HELLO,C#DEFGAB", "13:00,13:05,WORLD,ABCDEF" };
    vector<string> musicinfos4 = { "03:00,03:10,FOO,CCB#CCB", "04:00,04:08,BAR,ABC" };
    string s1 = solution(m1, musicinfos1);
    string s2 = solution(m2, musicinfos2);
    string s3 = solution(m3, musicinfos3);
    string s4 = solution(m4, musicinfos4);

    cout << s1 << s2 << s3 << s4;
}