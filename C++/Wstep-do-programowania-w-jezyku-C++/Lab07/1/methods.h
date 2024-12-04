using namespace std;
class Clock {
    private:
        int seconds;
        int minutes;
        int hours;
    
    public:
        // konstruktor domyślny
        Clock() {
            hours = 0;
            minutes = 0;
            seconds = 0;
        }
        
        // konstruktor z 3 argumentami
        Clock(int h, int m, int s) {
            hours = h;
            minutes = m;
            seconds = s;
        }
        
        
        void tick() {
            
            seconds++;
            if (seconds == 60) {
                seconds = 0;
                minutes++;
            }
            
            if (minutes == 60) {
                minutes = 0;
                hours++;
            }
            
            if (hours == 24) {
                hours = 0;
                minutes = 0;
                seconds = 0;
            }
            
            cout << "Czas po upływie jednej sekundy: " << hours << ":" << minutes << ":" << seconds << endl;
        }
        
        void actualTime() {
            cout << "Aktualna godzina: " << hours << ":" << minutes << ":" << seconds << endl;
        }
    
        void addTime(int h, int m, int s) {
            
            hours += h;
            minutes += m;
            seconds += s;
        
            int ile = seconds / 60;
            seconds = seconds % 60;
            minutes = minutes + ile;
            
            if (seconds < 0) {
                minutes--;
                seconds = 60 + seconds;
            }
            
            ile = minutes / 60;
            minutes = minutes % 60;
            hours = hours + ile;
            
            if (minutes < 0) {
                hours--;
                minutes = 60 + minutes;
            }
            
            if (hours >= 24) {
                hours = hours % 24;
            }
        }
        
        string isEqual(Clock secondClock) {
            if ((hours = secondClock.hours) and (minutes = secondClock.minutes) and (seconds = secondClock.seconds)) {
                return "Zegary pokazują tą samą godzinę";
            }
            
            else {
                return "Zegary nie pokazują tej samej godziny";
            }
    }
        
};