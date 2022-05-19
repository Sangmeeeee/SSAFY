#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

typedef struct music {
    string title;
    int playtime;
}music;

bool compare(music m1, music m2) {
    return m1.playtime > m2.playtime;
}

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

string split_akbo(string akbo, int len) {
    string subAkbo = "";

    int idx = 0;
    for (int i = 0; i < len;) {
        subAkbo += akbo[idx];
        if (akbo[idx] != '#')
            i++;
        idx++;
    }
    if (akbo[idx] == '#')
        subAkbo += akbo[idx];

    return subAkbo;
}

string getAllAkbo(string akbo, int playtime) {
    string allAkbo = "";

    int akboLength = (int)akbo.size();
    for (char c : akbo)
        if (c == '#') akboLength--;

    int iter = playtime / akboLength;
    if (iter == 0) {
        allAkbo = split_akbo(akbo, playtime);
    }
    else {
        for (int i = 0; i < iter; i++)
            allAkbo += akbo;

        int remain = playtime % akboLength;
        allAkbo += split_akbo(akbo, remain);
    }

    return allAkbo;
}

string solution(string m, vector<string> musicinfos) {
    vector<music> list;
    string answer = "";
    int max_playtime = 0;

    for (string musicinfo : musicinfos) {
        vector<string> info = split(musicinfo, ',');
        int playtime = getPlaytime(info[0], info[1]);
        string title = info[2];
        string allAkbo = getAllAkbo(info[3], playtime);

        int pos = (int)allAkbo.find(m);
        if (pos != string::npos) {
            list.push_back({ title, playtime });
            
            int len = (int)m.size();
            if (m[len - 1] != '#'
                && pos + len < (int)allAkbo.size()
                && allAkbo[pos + len] == '#')
                list.pop_back();
        }
    }

    sort(list.begin(), list.end(), compare);

    if ((int)list.size() == 0)
        answer = "(None)";
    else
        answer = list[0].title;

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