//*************************************************************
// Author: D.S. Malik
// 
// This program uses the classes videoType and videoBinaryTree 
// to create a list of videos for a video store. It performs 
// basic operations such as check in and check out videos.
//*************************************************************

#include <iostream>
#include <fstream>
#include <string>
#include "binarySearchTree.h"
#include "videoType.h"
#include "videoBinaryTree.h"

using namespace std;

void createVideoList(ifstream& infile, 
                     videoBinaryTree& videoList);
void displayMenu();
 
int main()
{
    videoBinaryTree  videoList;
    int choice;
    string title;

    ifstream infile;

    infile.open("c:\\videoDat.txt");
    if (!infile)
    {
        cout << "The input file does not exist. " 
             << "Program terminates!!"<< endl;
        return 1;
    }

    createVideoList(infile, videoList);
    infile.close();

    displayMenu();              //show the menu
    cout << "Enter your choice: ";		
    cin >> choice;              //get the request
    cin.ignore(100, '\n');      //ignore the remaining 
	                            //characters in the line
    cout << endl;

    while (choice != 9)
    {
        switch (choice)
        {
        case 1: 
            cout << "Enter the title: ";
            getline(cin, title);
            cout << endl;

            if (videoList.videoSearch(title))
                cout << "The store carries " << title << endl;
            else
                cout << "The store does not carry " << title
                     << endl;
            break;

        case 2: 
            cout << "Enter the title: ";
            getline(cin, title);
            cout << endl;

            if (videoList.videoSearch(title))
            {
                if (videoList.isVideoAvailable(title))
                {
                    videoList.videoCheckOut(title);
                    cout << "Enjoy your movie: " << title
                         << endl;
                }
                else
                    cout << "Currently " << title
                         << " is out of stock." << endl;
            }
            else
                cout << "The store does not carry " << title
                     << endl;
            break;

        case 3: 
            cout << "Enter the title: ";
            getline(cin, title);
            cout << endl;

            if (videoList.videoSearch(title))
            {
                videoList.videoCheckIn(title);
                cout << "Thanks for returning " << title
                     << endl;
            }
            else
                cout << "The store does not carry " << title
                     << endl;
            break;

        case 4: 
            cout << "Enter the title: ";
            getline(cin, title);
            cout << endl;

            if (videoList.videoSearch(title))
            {
                if (videoList.isVideoAvailable(title))
                    cout << title << " is currently in "
                         << "stock." << endl;
                else
                    cout << title << " is currently out "
                         << "of stock." << endl;
            }
            else
                cout << "The store does not carry " << title
                     << endl;
            break;

        case 5: 
            videoList.videoPrintTitle();
            break;

        case 6: 
            videoList.inorderTraversal();
            break;

        default: cout << "Invalid selection." << endl;
        	break;
        }//end switch

        displayMenu();          //display the menu
        cout << "Enter your choice: ";
        cin >> choice;          //get the next request
        cin.ignore(100, '\n');  //ignore the remaining 
                                //characters in the line
        cout << endl;
    }//end while

    return 0;
}

void createVideoList(ifstream& infile, 
                     videoBinaryTree& videoList)
{
    string title;
    string star1;
    string star2;
    string producer;
    string director;
    string productionCo;
    int inStock;

    videoType newVideo;

    getline(infile, title);

    while (infile)
    {
        getline(infile, star1);
        getline(infile, star2);
        getline(infile, producer);
        getline(infile, director);
        getline(infile, productionCo);
        infile >> inStock;
        infile.ignore(100, '\n');
        newVideo.setVideoInfo(title, star1, star2, producer,
                              director, productionCo, inStock);
        videoList.insert(newVideo);

        getline(infile, title);
    }//end while
}//end createVideoList

void displayMenu()
{
    cout << "Select one of the following:" << endl;
    cout << "1: To check whether the store carries a "
         << "particular video." << endl;
    cout << "2: To check out a video." << endl;
    cout << "3: To check in a video." << endl;
    cout << "4: To check whether a particular video is " 
         << "in stock." << endl;
    cout << "5: To print only the titles of all the videos."
         << endl;
    cout << "6: To print a list of all the videos." << endl;
    cout << "9: To exit" << endl;
}

