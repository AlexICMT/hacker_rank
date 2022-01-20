/*
 * 				magic_spells.cpp
 *				/hacker_rank/src/magic_spells.cpp
 *
 *  Created on: 20 янв. 2022 г.
 *      Author: alexicmt
 */

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Spell {
    private:
        string scrollName;
    public:
        Spell(): scrollName("") { }
        Spell(string name): scrollName(name) { }
        virtual ~Spell() { }
        string revealScrollName() {
            return scrollName;
        }
};

class Fireball : public Spell {
    private: int power;
    public:
        Fireball(int power): power(power) { }
        void revealFirepower(){
            cout << "Fireball: " << power << endl;
        }
};

class Frostbite : public Spell {
    private: int power;
    public:
        Frostbite(int power): power(power) { }
        void revealFrostpower(){
            cout << "Frostbite: " << power << endl;
        }
};

class Thunderstorm : public Spell {
    private: int power;
    public:
        Thunderstorm(int power): power(power) { }
        void revealThunderpower(){
            cout << "Thunderstorm: " << power << endl;
        }
};

class Waterbolt : public Spell {
    private: int power;
    public:
        Waterbolt(int power): power(power) { }
        void revealWaterpower(){
            cout << "Waterbolt: " << power << endl;
        }
};

class SpellJournal {
    public:
        static string journal;
        static string read() {
            return journal;
        }
};
string SpellJournal::journal = "";

void counterspell(Spell *spell)
{
	string revealedScroll;
	Fireball		*fire 			= dynamic_cast<Fireball*>(spell);
	Frostbite		*frost 			= dynamic_cast<Frostbite*>(spell);
	Waterbolt		*water 			= dynamic_cast<Waterbolt*>(spell);
	Thunderstorm	*thunder 		= dynamic_cast<Thunderstorm*>(spell);
	if(fire != nullptr)
		fire->revealFirepower();
	else if(frost != nullptr)
		frost->revealFrostpower();
	else if(water != nullptr)
		water->revealWaterpower();
	else if(thunder != nullptr)
		thunder->revealThunderpower();
	else
		{
		revealedScroll = spell->revealScrollName();
		string journal = SpellJournal::read();
		vector<char> coincidences;
		int sizeA = static_cast<int>(revealedScroll.size()), sizeB = static_cast<int>(journal.size());
		/*
		//cout << sizeA << ' ' << sizeB << endl;
		if(revealedScroll.size() >= journal.size())
		{
			for(int i = 0; i < sizeA; i++)
			{
				for(int j = 0; j < sizeB; j++)
				{
					if(revealedScroll[i] == journal[j])
					{
						coincidences.push_back(revealedScroll[i]);
						journal.erase(j, 1);
						//cout << journal << endl;
						break;
					}
				}
			}
			cout << coincidences.size() << endl;
		}
		else
		{
			for(int i = 0; i < sizeB; i++)
			{
				for(int j = 0; j < sizeA; j++)
				{
					if(journal[i] == revealedScroll[j])
					{
						coincidences.push_back(journal[i]);
						revealedScroll.erase(j, 1);
						//cout << revealedScroll << endl;
						break;
					}
				}
			}
			cout << coincidences.size() << endl;
		}
		/*
		for(char i: coincidences)
			cout << i;
		cout << endl;
		*/


		std::string strA = spell->revealScrollName();
		        std::string strB = SpellJournal::read();

		    int m = strA.length();
		    int n = strB.length();

		    std::vector<std::vector<int>> vLCSMatrix(m + 1, std::vector<int>(n + 1));

		    for (int i = 1; i <= m; i++)
		    {
		        for (int j = 1; j <= n; j++)
		        {
		            if (strA[i - 1] == strB[j - 1])
		            {
		                vLCSMatrix[i][j] = 1 + vLCSMatrix[i - 1][j - 1];
		            }
		            else
		            {
		                vLCSMatrix[i][j] = std::max(vLCSMatrix[i - 1][j], vLCSMatrix[i][j - 1]);
		            }
		        }
		    }

		     std::cout << vLCSMatrix[m][n] << std::endl;

		}

}
//AquaVitae 999 AruTaVae

class Wizard {
    public:
        Spell *cast() {
            Spell *spell;
            string s; cin >> s;
            int power; cin >> power;
            if(s == "fire") {
                spell = new Fireball(power);
            }
            else if(s == "frost") {
                spell = new Frostbite(power);
            }
            else if(s == "water") {
                spell = new Waterbolt(power);
            }
            else if(s == "thunder") {
                spell = new Thunderstorm(power);
            }
            else {
                spell = new Spell(s);
                cin >> SpellJournal::journal;
            }
            return spell;
        }
};

int no_main_5() {
    int T;
    cin >> T;
    Wizard Arawn;
    while(T--) {
        Spell *spell = Arawn.cast();
        counterspell(spell);
    }
    return 0;
}


