
//***********************************************************
// Author: D.S. Malik
// 
// class videoBinaryTree
// This class extends the class bSearchTreeType to create
// a video list.
//***********************************************************

#ifndef H_VideoLinkedListType
#define H_VideoLinkedListType
 
#include <iostream>
#include <string>
#include "binarySearchTree.h"
#include "videoType.h"

using namespace std;

class videoBinaryTree:public bSearchTreeType<videoType>
{
public:
    bool videoSearch(string title);
      //Function to search the list to see whether a
      //particular title, specified by the parameter title,
      //is in the store.
      //Postcondition: Returns true if the title is found,
      //               and false otherwise.

    bool isVideoAvailable(string title);
      //Function to determine whether a copy of a particular 
      //video is in the store.
      //Postcondition: Returns true if at least one copy of 
      //               the video specified by title is in the 
      //               store,and false otherwise.

    void videoCheckIn(string title);
      //Function to check in a video returned by a customer
      //Postcondition: copiesInStock is incremented by one.

    void videoCheckOut(string title);
      //Function to check out a video, that is, rent a video.
      //Postcondition: copiesInStock is decremented by one.

    bool videoCheckTitle(string title) const;
      //Function to determine whether a particular video is in
      //the store.
      //Postcondition: Returns true if the video’s title is
      //               the same as title, and false otherwise.

    void videoUpdateInStock(string title, int num);
      //Function to update the number of copies of a video
      //by adding the value of the parameter num. The 
      //parameter title specifies the name of the video for
      //which the number of copies is to be updated.
      //Postcondition: copiesInStock = copiesInStock + num;

    void videoSetCopiesInStock(string title, int num);
      //Function to reset the number of copies of a video.
      //The parameter title specifies the name of the video
      //for which the number of copies is to be reset, and 
      //the parameter num specifies the number of copies.
      //Postcondition: copiesInStock = num;

    void videoPrintTitle() const;
      //Function to print the titles of all the videos in 
      //the store.

private:
    void searchVideoList(string title, bool& found,
                         nodeType<videoType>* &current) const;
      //This function searches the video list for a 
      //particular video, specified by the parameter title. 
      //If the video is found, the parameter found is set to 
      //true, otherwise false; the parameter current points  
      //to the node containing the video.

    void inorderTitle(nodeType<videoType> *p)  const;
      //This function prints the titles of all the videos
      //in stock. 
};

#endif