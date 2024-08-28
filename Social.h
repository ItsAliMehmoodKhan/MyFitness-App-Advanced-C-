#pragma once
#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "1.h"
#include <cstring>

using namespace std;
class Social
{
public:
	void menu(string un)
	{
		cout << "\n\t\t\t\t\t\t    Social Interaction Menu:\n";
		cout << "\t\t\t\t\t\t    1] Post to Social Feed\n";
		cout << "\t\t\t\t\t\t    2] View Social Feed\n";
		cout << "\t\t\t\t\t\t    3] Follow Users\n";
		cout << "\t\t\t\t\t\t    4] Unfollow Users\n";
		cout << "\t\t\t\t\t\t    5] Direct Messaging\n";
		selection(un);
	}


	void selection(string un)
	{
		int n;
		while (true)
		{
			cin >> n;
			if (n == 1 || n == 2 || n == 3 || n == 4 || n == 5)
			{
				break;
			}
			else
				cout << "\t\t\t\t\t\t    Invalid Input, Try again\n";
		}

		if (n == 1)
		{
			post_tosocialFeed(un);
		}
		if (n == 2)
		{
			viewSocialFeed(un);
		}
		if (n == 3)
		{
			followUsers(un);
		}
		if (n == 4)
		{
			unfollowUsers(un);
		}
		if (n == 5)
		{
			directMessaging(un);
		}


	}


	//---------------------------------------------------------------------------------------------------------------------//

	void post_tosocialFeed(string un)
	{
		fstream socialFeed;
		socialFeed.open("Social Feed.txt", ios::binary | ios::app);
		if (socialFeed.is_open() == 0)
		{
			cout << "\t\t\t\t\t\t    Error Opening Social Feed\n";
		}

		string SF;
		cout << "\t\t\t\t\t\t    Note: This post cannot be deleted and \n\t\t\t\t\t\t    will shown to the whole Hub\n";
		cout << "\t\t\t\t\t\t    Enter the post:";
		cin.ignore();
		getline(cin, SF);

		socialFeed << un << ": ";
		socialFeed << SF;
		socialFeed << endl;

		cout << "\t\t\t\t\t\t    Post sent successfully\n";

		socialFeed.close();
	}


	//-------------------------------------------------------------------------------------------------------------------------//

	void viewSocialFeed(string un)
	{
		fstream viewFeed;
		viewFeed.open("Social Feed.txt", ios::binary | ios::in);
		if (viewFeed.is_open() == 0)
		{
			cout << "\t\t\t\t\t\t    Error Opening Social Feed\n";
		}
		string line;
		cout << "\n\n\t\t\t\t\t\t\t    Social Feed:\n\n";
		cout << "\t\t\t\t\t    (Biggest Group where you can share everything\n\t\t\t\t\t     about your health and get amazing tips)\n";


		while (getline(viewFeed, line, '\n'))
		{
			cout << "\t\t\t\t\t    " << line << endl;
		}

		viewFeed.close();


	}


	//-------------------------------------------------------------------------------------------------------------------------------//

	void followUsers(string un)
	{
		fstream follow;
		follow.open("user_username.txt", ios::binary | ios::in);
		if (follow.is_open() == 0)
		{
			cout << "\t\t\t\t\t\t    Error Opening Social Feed\n";
		}

		string friends;
		cout << "List of Users" << endl;
		while (getline(follow, friends, '\n'))
		{
			cout << "\t\t\t\t\t\t" << friends << endl;
		}
		string f;
		cout << "\t\t\t\t\t\t    Enter the name of user you want to send friend request to:";
		cin >> f;

		fstream UserFriends;
		UserFriends.open(un + "'s_Friends.txt", ios::binary | ios::app);
		fstream friendsUser;
		friendsUser.open(f + "'s_Friends.txt", ios::binary | ios::app);
		if (UserFriends.is_open() == 0)
		{
			cout << "\t\t\t\t\t\t    Error opening File\n";
		}
		if (friendsUser.is_open() == 0)
		{
			cout << "\t\t\t\t\t\t    Error opening File\n";
		}

		UserFriends << f;
		UserFriends << endl;
		friendsUser << un;
		friendsUser << endl;



		follow.close();
		UserFriends.close();
		friendsUser.close();
	}

	//------------------------------------------------------------------------------------------------------------------------------//


	void unfollowUsers(const std::string& un) {

		ifstream userFriendsFile(un + "'s_Friends.txt");
		if (!userFriendsFile.is_open()) {
			cout << "\t\t\t\t\t\t    Error opening user's friends file." << endl;
			return;
		}

		// Display the list of user's friends
		cout << "\t\t\t\t\t\t    List of your friends: " << endl;
		string friendName;
		while (getline(userFriendsFile, friendName)) {
			cout << "\t\t\t\t\t\t    " << friendName << endl;
		}
		userFriendsFile.close();

		// Get the name of the friend to remove
		string friendToRemove;
		cout << "\t\t\t\t\t\t    Enter the name of your friend that you want to remove: ";
		cin >> friendToRemove;

		// Open a temporary file to store the updated list of friends
		ofstream tempFile("temp.txt");
		if (!tempFile.is_open()) {
			cout << "\t\t\t\t\t\t    Error creating temporary file." << endl;
			return;
		}

		// Rewrite the user's friends file, excluding the friend to remove
		userFriendsFile.open(un + "'s_Friends.txt");
		if (!userFriendsFile.is_open()) {
			cout << "\t\t\t\t\t\t    Error opening user's friends file for rewriting." << endl;
			return;
		}

		while (getline(userFriendsFile, friendName)) {
			if (friendName != friendToRemove) {
				tempFile << friendName << endl;
			}
		}
		userFriendsFile.close();
		tempFile.close();

		// Rename the temporary file to replace the original user's friends file
		if (rename("temp.txt", (un + "'s_Friends.txt").c_str()) != 0) {
			cout << "\t\t\t\t\t\t    Friend Removed." << endl;
			return;
		}

		cout << "\t\t\t\t\t\t    Friend removed successfully." << endl;
	}



	//-----------------------------------------------------------------------------------------------------------//

	void directMessaging(string un)
	{
		cout << "\t\t\t\t\t\t    InBox \n";
		fstream friends;
		friends.open(un + "'s_Friends.txt", ios::binary | ios::in);
		if (friends.is_open() == 0)
		{
			cout << "\t\t\t\t\t\t    Cannot open file\n";
		}
		string c;
		cout << "\t\t\t\t\t\t    List of your friends \n";
		while (getline(friends, c, '\n'))
		{
			cout << c << endl;
		}
		string f;
		cout << "\t\t\t\t\t\t    Enter name of your friend you want to chat with\n";
		cin >> f;


		fstream messages;
		fstream messages2;
		messages.open(un + "_Messages with_" + f, ios::binary | ios::in);
		messages2.open(f + "_Messages with_" + un, ios::binary | ios::in);

		if (messages.is_open() == 0)
		{
			cout << "\t\t\t\t\t\t    Chats cannot be opened\n";
		}
		if (messages2.is_open() == 0)
		{
			cout << "\t\t\t\t\t\t    Chats cannot be opened\n";
		}

		string a, b;
		while (getline(messages, a, '\n'))
		{
			cout << "\t\t\t\t\t\t" << a << endl;
		}



		friends.close();
		messages.close();
		messages2.close();

		messages.open(un + "_Messages with_" + f, ios::binary | ios::app);
		messages2.open(f + "_Messages with_" + un, ios::binary | ios::app);

		if (messages.is_open() == 0)
		{
			cout << "\t\t\t\t\t\t    Chats cannot be opened\n";
		}
		if (messages2.is_open() == 0)
		{
			cout << "\t\t\t\t\t\t    Chats cannot be opened\n";
		}

		cout << "Enter message: " << endl;
		cin.ignore();
		getline(cin, b);

		messages << un << ':' << b;
		messages << endl;
		messages2 << un << ':' << b;
		messages2 << endl;


		messages.close();
		messages2.close();
	}


};
