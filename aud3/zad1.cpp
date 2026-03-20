//
// Created by David Arsov on 11.3.26.
//

#include<iostream>

using namespace std;

// Да се дефинира класа Team што содржи информации за име на екипата, година на формирање
// и градот од каде потекнува.

class Team {
private:
    char name[100];
    int year;
    char city[100];

public:
    Team(char* _name, int _year, char* _city) {
        strcpy(name, _name);
        year = _year;
        strcpy(city, _city);
    }

    Team() {

    }

    char* getName() {
        return name;
    }
};

class Game {
private:
    Team host;
    Team guest;
    int hostGoals;
    int guestGoals;

public:
    Game(Team _host, Team _guest) {
        host = _host;
        guest = _guest;
        hostGoals = 0;
        guestGoals = 0;
    }

    Game(Team _host, Team _guest, int _hostGoals, int _guestGoals) {
        host = _host;
        guest = _guest;
        hostGoals = _hostGoals;
        guestGoals = _guestGoals;
    }

    Team getGuest() const {
        return guest;
    }

    Team getHost() const{
        return host;
    }

    int getHostGoals() const {
        return hostGoals;
    }

    int getGuestGoals() const {
        return guestGoals;
    }
};

// Да се дефинира класа Game што содржи информации за домаќин, гостин (објекти од класата Team),
// голови кои ги постигнал домаќинот и голови кои ги постигнал гостинот.

//Game 1 host: T1 guest: T2
//Game 2 host: T2 guest: T1

bool revans(const Game game1, const Game game2) {
    if (strcmp(game1.getHost().getName(), game2.getGuest().getName()) == 0
        && strcmp(game1.getGuest().getName(), game2.getHost().getName()) == 0) {
        return true;
    }
    // else {
    //     return false;
    // }
    return false;
}

Team duel(const Game game1, const Game game2) {
    bool r = revans(game1, game2);

    if (r == true) {
        int team1Goals = game1.getHostGoals() + game2.getGuestGoals();
        int team2Goals= game1.getGuestGoals() + game2.getHostGoals();

        if (team1Goals > team2Goals) {
            return game1.getHost();
        } else if (team2Goals > team1Goals) {
            return game1.getGuest();
        } else {
            return Team();
        }
    } else {
        cout << "Natprevarite ne se sovpagjaat";
    }
}

int main() {

    Team t1("Team1", 2000, "Skopje");
    Team t2("Team2", 2001, "Bitola");
    Team t3("Team3", 2002, "Prilep");

    Game g1(t1, t2, 1, 2);
    Game g2(t2, t1, 3, 0);

    Game g3(t1, t3, 1, 1);
    Game g4(t3, t1, 1, 1);

    Game g5(t2, t3, 2, 1);

    cout << "Revans: " << revans(g1, g2) << endl;
    cout << "Revans: " << revans(g3, g4) << endl;
    cout << "Revans: " << revans(g5, g2) << endl;

    Team winner = duel(g1, g2);
    cout << winner.getName() << endl;

    Team winner2 = duel(g3, g4);
    cout << winner2.getName() << endl;
    return 0;
}