#include <iostream>
#include <string>
#include <map>

using namespace std;


struct TeamPhase {
    string _phase_id;
    string _team_id;

    bool operator == (const TeamPhase& t) const {
        return (0 == _phase_id.compare(t._phase_id)) && (0 == _team_id.compare(t._team_id));
    }

    bool operator < (const TeamPhase& t) const {
        int ret = _phase_id.compare(t._phase_id);
        if (0 == ret)
            return (_team_id.compare(t._team_id) < 0) ? true : false;
        else
            return (ret < 0) ? true : false;
    }
};

int main(int argc, char *argv[]) {
    map<TeamPhase, int> mt;
    map<TeamPhase, int>::iterator it;

    TeamPhase phase;
    phase._phase_id = "1";
    phase._team_id = "101";

    mt.insert(pair<TeamPhase, int>(phase, 110));

    phase._team_id = "202";
    mt.insert(pair<TeamPhase, int>(phase, 123));

    phase._phase_id = "2";
    phase._team_id = "303";
    mt.insert(pair<TeamPhase, int>(phase, 236));

    phase._phase_id = "3";
    phase._team_id = "203";
    mt.insert(pair<TeamPhase, int>(phase, 320));

    for(it = mt.begin(); it != mt.end(); it++) {
        cout << it->first._phase_id << "|" << it->first._team_id << ": " << it->second << endl;
    }

    cout << "Found: " << mt[phase] << endl;

    getchar();
    return 0;
}
