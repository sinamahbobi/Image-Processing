/* IMPORTANT NOTES:
 * This is just a sample code.
 * You may/should change/delete many parts of this file.
 * You can just get some hints on how to start your code here.
 * DO NOT consider this file as a template. 
 */


#include <iostream>
#include "bmplib.h"
#include "imagefunctions.h"
#include "dirent.h"
#include <string>
#define PATH_IN "/home/student/ee355/ee355-lab6-sinamahbobi/original-photos/"
#define PATH_OUT "/home/student/ee355/ee355-lab6-sinamahbobi/modified-photos/"
#include <iterator> // for iterators 
#include <vector> // for vectors 
using namespace std;


void showMainMenu(){
    cout << "0: Exit \n";
    cout << "1: Flip 90 Degrees Clockwise \n";
    cout << "2: Flip Image 180 Degrees \n";
    cout << "3: Mirror Image \n";
    cout << "4: Grey Scale Image \n";
    cout << "5: Color Inversion \n";
    cout << "6: Zoom In \n";
}




 vector <string> imageLoader() {

            DIR *dir;
            struct dirent *ent;
            char targetFolderAddr[] = "./";
            vector <string> fileArray;
            int filecount = 0;
            
                if ((dir = opendir (PATH_IN)) != NULL) {
       
                while ((ent = readdir (dir)) != NULL) {
                   string name = ent -> d_name;
                    if (name.length() >3 && name.substr(name.length()-3) == "bmp") {
                        //cout << name << endl;
                        fileArray.push_back(name);
                        //cout <<fileArray;//filecount++;
            
            }
          
            }
            closedir (dir);
            }


            for (int i = 0; i < fileArray.size(); i++) {

                cout <<fileArray[i]<<endl;
            }
            cout << "\n";
            return fileArray;


            // TODO: print all the files in this same directory that have ".db" format
           /* int flag =0;// Take a look into sample_files.cpp 
            cout << "Enter the file name of the image: "; 
            string fileName;
            cin >> fileName;
                for (int i = 0; i < filecount ; i++) {
                if(fileName == fileArray[i] ) {
                    flag =1;
                    break;
                
                }
               
            }   

            // If file with name FILENAME does not exist: 
            if (flag ==1  ) {
                cout << "Image loaded! \n"; 
                return fileName;
            }
            else {
                cout << "Image " << fileName <<" does not exist!" << endl;
                return "";//imageLoader();//return;
            } */


} 

int main(){

    int option;
    //unsigned char res [SIZE][SIZE][3];
    while(1){
        cout << "\033[2J\033[1;1H";
        vector <string> imageName = imageLoader();
        
        showMainMenu();
        cout << "Select an option: ";
        cin >> option;
        switch(option){
            case 0:
                cout << "EXIT \n";;
                return 0;
            case 1: 
                cout << "FLIP IMAGE 90 DEGREES CLOCKWISE \n";
                unsigned char src1[SIZE][SIZE][RGB];
                unsigned char dest1[SIZE][SIZE][RGB];
                
                for (int i = 0; i < imageName.size(); i++) {
                
                string inImage = PATH_IN + imageName[i];
                readRGBBMP(inImage.c_str(), src1);
                flip90(src1, dest1);
                showRGBBMP(dest1);
                string outImage = PATH_OUT + imageName[i];
                writeRGBBMP(outImage.c_str(), dest1);   }

                break;
            case 2: 
                cout << "FLIP IMAGE 180 DEGREES \n";;
                unsigned char src2[SIZE][SIZE][RGB];
                unsigned char dest2[SIZE][SIZE][RGB];
                
                for (int i = 0; i < imageName.size(); i++) {
                
                string inImage = PATH_IN + imageName[i];
                readRGBBMP(inImage.c_str(), src2);
                flip180(src2, dest2);
                showRGBBMP(dest2);
                string out = PATH_OUT + imageName[i];
                writeRGBBMP(out.c_str(), dest2); }
                break;
            case 3:
                cout << "MIRROR IMAGE \n";
                unsigned char src3[SIZE][SIZE][RGB];
                unsigned char dest3[SIZE][SIZE][RGB];
                
                for (int i = 0; i < imageName.size(); i++) {
                string inImage = PATH_IN + imageName[i];
                readRGBBMP(inImage.c_str(), src3);
                mirror(src3, dest3);
                showRGBBMP(dest3);
                string out = PATH_OUT + imageName[i];
                writeRGBBMP(out.c_str(), dest3); }
                break;
            case 4:
                //string image = imageLoader();
                cout << "GREY SCALE IMAGE \n";
                unsigned char src4[SIZE][SIZE][RGB];
                unsigned char dest4[SIZE][SIZE];

                for (int i = 0; i < imageName.size(); i++) {
                string inImage = PATH_IN + imageName[i];
                readRGBBMP(inImage.c_str(), src4);
                grey_scale(src4, dest4);
                showGSBMP(dest4);
                string out = PATH_OUT + imageName[i];
                writeGSBMP(out.c_str(), dest4); }
                
                break;
            case 5:
                cout << "COLOR INVERSION \n";
                unsigned char src5[SIZE][SIZE][RGB];
                unsigned char dest5[SIZE][SIZE][RGB];
                
                for (int i = 0; i < imageName.size(); i++) {
                string inImage = PATH_IN + imageName[i];
                readRGBBMP(inImage.c_str(), src5);
                color_inversion(src5, dest5);
                showRGBBMP(dest5);
                string out = PATH_OUT + imageName[i];
                writeRGBBMP(out.c_str(), dest5); }
                break;
            case 6:
                cout<<"ZOOM IN \n";
                unsigned char src6[SIZE][SIZE][RGB];
                unsigned char dest6[SIZE][SIZE][RGB];

                for (int i = 0; i < imageName.size(); i++) {
                string inImage = PATH_IN + imageName[i];
                readRGBBMP(inImage.c_str(), src6);
                zoom_in(src6, dest6);
                showRGBBMP(dest6);
                string out = PATH_OUT + imageName[i];
                writeRGBBMP(out.c_str(), dest6); }
                break;
            default:
                cout << "OPTION NOT FOUND! \n";
                break;
        }
    
}
    return 0;
}
