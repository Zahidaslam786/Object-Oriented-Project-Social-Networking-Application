#include<iostream>
#include<string>
#include<fstream>
using namespace std;


//------------------------------------------ SOCIALENTITY -------------------------------------------------
class SocialEntity
{
protected:
    string name;
    int id;
public:
    SocialEntity()
    {
        name = "null";
        id = 0;
    }

    static void GetTime();
    SocialEntity(string n, int i);
    string getName() const;
    int getId() const;
};

SocialEntity::SocialEntity(string n, int i)
    : name(n), id(i) {}
string SocialEntity::getName() const
{
    return name;
}
int SocialEntity::getId() const
{
    return id;
}

void SocialEntity::GetTime()
{
    cout << __DATE__ << " , " << __TIME__ << endl;
}
//------------------------------------------- POST Class--------------------------------------------------------
string details;
class Post : public SocialEntity
{
protected:
    int post_id;
    string type;
    int total_likes;
public:
    static int n_post;
    Post()
    {
        post_id = 0;
        type = "null";
        details = "null";
        total_likes = 0;
    }
    Post(int id, string postType, const string postdetails);
    Post(string t) : type(t) {}
    void new_post(int id);
    void displayPost() const;
    string getType() const;
    string getdetails() const;
    int getpost_id() const;
    void gettotal_likes(int post_id);
    void display_total_likes() const; //Display total likes
    void sharePost(int post_id, int userId, string Name) const;
    bool containsKeyword(const string& keyword) const;
    virtual void Postdata(); //virtual Function
    ~Post() {}
};
int Post::n_post = 0;
void Postdetails(string type);   //----------Function Porotype -----------

////--------------CLASSES For POST DETIALS ---------------------------------
class FeelingPost :public Post
{
public:
    FeelingPost(string t) :Post(t) {}
    virtual void Postdata() override;
};

void FeelingPost::Postdata()
{
    cout << "the type of the post is : " << type << "\n";
    cout << "Enter details For The Post: ";
    cin.ignore();
    getline(cin, details);

    ofstream postFile("Posts.txt", ios::app);
    if (postFile.is_open())
    {
        postFile << "\nPost ID: " << ++n_post << endl;
        postFile << "Post Type: " << getType() << endl;
        postFile << "details: " << details << endl;
        postFile << "------------------------" << endl;
        postFile << endl;
        postFile.close();
    }
    else
    {
        cout << "Unable to open" << endl;
    }

}
class ThinkingPost :public Post
{
public:
    ThinkingPost(string t) :Post(t) {}
    virtual void Postdata() override;
};

void ThinkingPost::Postdata()
{
    cout << "the type of the post is : " << type << "\n";
    cout << "Enter details For The Post: ";
    cin.ignore();
    getline(cin, details);
    ofstream postFile("Posts.txt", ios::app);
    if (postFile.is_open())
    {
        postFile << "\nPost ID: " << ++n_post << endl;
        postFile << "Post Type: " << getType() << endl;
        postFile << "details: " << details << endl;
        postFile << "------------------------" << endl;
        postFile << endl;
        postFile.close();
    }
    else
    {
        cout << "Unable to open" << endl;
    }
}
class MakingPost :public Post
{
public:
    MakingPost(string t) :Post(t) {}
    virtual void Postdata() override;
};

void MakingPost::Postdata()
{
    cout << "the type of the post is : " << type << "\n";
    cout << "Enter details For The Post: ";
    cin.ignore();
    getline(cin, details);
    ofstream postFile("Posts.txt", ios::app);
    if (postFile.is_open())
    {
        postFile << "\nPost ID: " << ++n_post << endl;
        postFile << "Post Type: " << getType() << endl;
        postFile << "details: " << details << endl;
        postFile << "------------------------" << endl;
        postFile << endl;
        postFile.close();
    }
    else
    {
        cout << "Unable to open" << endl;
    }
}

class CelebratingPost :public Post
{
public:
    CelebratingPost(string t) :Post(t) {}
    virtual void Postdata() override;
};

void CelebratingPost::Postdata()
{
    cout << "the type of the post is : " << type << "\n";
    cout << "Enter details For The Post: ";
    cin.ignore();
    getline(cin, details);
    ofstream postFile("Posts.txt", ios::app);
    if (postFile.is_open())
    {
        postFile << "\nPost ID: " << ++n_post << endl;
        postFile << "Post Type: " << getType() << endl;
        postFile << "details: " << details << endl;
        postFile << "------------------------" << endl;
        postFile << endl;
        postFile.close();
    }
    else
    {
        cout << "Unable to open" << endl;
    }
}
//-------------------- Functions Defination Of Post Class ----------------------
void Post::Postdata()
{
}

//Post::Post(int id, string postType, const string postdetails)
//    : post_id(id), type(postType), details(postdetails), total_likes(0)
//{}
Post::Post(int id, string postType, const string postdetails)
    : post_id(id), type(postType), total_likes(0)
{}
void Post::new_post(int id)
{
    post_id = id;
    cout << "\nCreate a new post:" << endl;

    cout << "\t\t\tSelect Post Type:\n" << endl;
    cout << "\n\t\t 1. \"Feeling\"     (Happy/Sad/Excited etc)" << endl;
    cout << "\n\t\t 2. \"Thinking\"   (Life/Future/Meaning of life etc)" << endl;
    cout << "\n\t\t 3. \"Making\"      (Money/Art/Memories etc)" << endl;
    cout << "\n\t\t 4. \"Celebrating\"  (A birthday/Halloween/Success etc)\n\n" << endl;

    int choice;
    cout << "Enter the type number: ";
    cin >> choice;
    switch (choice)
    {
    case 1:
        type = "Feeling";
        Postdetails(type);
        break;
    case 2:
        type = "Thinking";
        Postdetails(type);
        break;
    case 3:
        type = "Making";
        Postdetails(type);
        break;
    case 4:
        type = "Celebrating";
        Postdetails(type);
        break;
    default:
        cout << "Invalid choice!" << endl;
        cin >> choice;
    }
}


string Post::getType() const
{
    return type;
}
string Post::getdetails() const
{
    return details;
}
int Post::getpost_id() const
{
    return post_id;
}

void Post::displayPost() const
{
    cout << "------------- Post ------------" << endl;
    ifstream myfile("Posts.txt", ios::app);
    if (myfile.is_open())
    {
        string str;
        while (getline(myfile, str))
        {
            cout << str << endl;
        }
        myfile.close();
    }
    else
    {
        cout << "Unable to open" << endl;
    }

}
void Post::gettotal_likes(int post_id)// To get likes
{
    ifstream likesFile("likes.txt");
    int post, userId;
    if (likesFile.is_open())
    {
        while (likesFile)
        {
            likesFile >> post >> userId;
            if (post == post_id)
            {
                cout << "The Post Liked By User : " << userId << endl;
                total_likes++;
            }
        }
        likesFile.close();
    }
    else
    {
        cout << "Failed to open 'likes.txt'." << endl;
    }
}
void Post::display_total_likes() const//To display total likes
{
    cout << "------------Total Likes-----------" << endl;
    cout << "Total Likes: " << total_likes << endl;
}
void Post::sharePost(int post_id, int userId, string Name) const
{
    ofstream time_line("timelinesharedposts.txt", ios::app);// writing shared posts
    if (time_line.is_open())
    {
        time_line << "User ID: " << userId << endl;
        time_line << "Post ID: " << post_id << endl;
        time_line << "User Name: " << Name << endl;
        time_line << "Post details: " << details << endl;
        time_line << "------------------------" << endl;

        // Close the file
        time_line.close();
        cout << "\n\t\tPost shared successfully." << endl;
    }
    else
    {
        cout << "Failed to open 'timelinesharedposts.txt' for writing." << endl;
    }

}

bool Post::containsKeyword(const string& keyword) const
{
    const string& postDetails = details;
    const string& searchWord = keyword;

    int postLen = postDetails.length();
    int wordLen = searchWord.length();

    bool found = true;
    for (int i = 0; i <= postLen - wordLen; i++)
    {

        for (int j = 0; j < wordLen; j++)
        {
            if (postDetails[i + j] != searchWord[j])
            {
                return  false;
                break;
            }
            else
            {
                return true;
            }
        }
    }
}
//Polymorphism 
void Postdetails(string type)
{
    if (type == "Feeling")
    {
        Post* Feeling = new FeelingPost(type);
        Feeling->Postdata();
    }
    else if (type == "Thinking")
    {
        Post* Thinking = new ThinkingPost(type);
        Thinking->Postdata();
    }
    else if (type == "Making")
    {
        Post* Making = new MakingPost(type);
        Making->Postdata();
    }
    else if (type == "Celebrating")
    {
        Post* Celebrating = new CelebratingPost(type);
        Celebrating->Postdata();
    }
}

//-----------------------------------------------------------------------------------------------------------
//--------------------------------- USER Class---------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------
class User : public Post
{
private:
    int currentUserID;
    string currentUserName;
    string* frd_list;
    int n_friend;
    int no_posts;
public:
    const int size = 10;
    Post* posts = new Post[size];
    User() : currentUserID(0), currentUserName(""), frd_list(nullptr), n_friend(0), no_posts(0) {}
    void setCurrentUser(int id, const string& name);
    int getCurrentUser() const;
    string getCurrentUserName() const;
    void addFriends(int numFriends, const string* userList, int userListSize);
    void displayfrd_list() const;
    void virtual new_post();
    void displayPosts() const;
    int getno_posts() const;
    void friendsposts() const;
    void addComment(int post_id, string comment);
    void Display_comments(int post_id) const;
    void displayTimeline() const;
    void displayHome() const;
    void searchPostsByKeyword(const string& keyword) const;
    ~User()
    {
        delete[] frd_list; // Deallocate memory for the friend list
    }
};
void User::setCurrentUser(int id, const string& name)
{
    currentUserID = id;
    currentUserName = name;
}
int User::getCurrentUser() const
{
    return currentUserID;
}
string User::getCurrentUserName() const
{
    return currentUserName;
}
void User::addFriends(int numFriends, const string* userList, int userListSize)
{

    string* newfrd_list = new string[n_friend + numFriends]; // For the new friend list

    for (int i = 0; i < n_friend; i++)// Copy existing friends
    {
        newfrd_list[i] = frd_list[i];
    }
    for (int i = 0; i < numFriends; i++)// Add new friends to the end of the list
    {
        string friendName;    //add new friend 
        bool exsist = false;
        do
        {
            cout << "Enter the name of friend " << (i + 1) << ": ";
            cin >> friendName;
            if (friendName == getCurrentUserName())
            {
                cout << "Invalid friend! (You cannot make yourself a friend) " << endl;
            }
            else
            {
                for (int j = 0; j < userListSize; j++)//check friend list
                {
                    if (userList[j] == friendName)
                    {
                        exsist = true;
                        break;
                    }
                }
                if (exsist == false)   //false
                {
                    cout << "Friend Not Found!  Please Enter again" << endl;
                }
            }
        } while (!exsist);
        newfrd_list[n_friend + i] = friendName; //add new friends in dynamic friend list
    }
    frd_list = newfrd_list;// Update the friend
    n_friend += numFriends;// Update count
    ofstream friendFile("friend.txt", ios::app);
    if (friendFile.is_open())
    {
        friendFile << "Friend List of " << currentUserName << " (ID: " << currentUserID << "):" << endl;
        for (int i = 0; i < n_friend; i++)
        {
            friendFile << frd_list[i] << endl;
        }
        friendFile << "------------------------" << endl;
        friendFile.close();
        cout << "Friend List Store" << endl;
    }
    else
    {
        cout << "Unable to Open" << endl;
    }
}
void User::displayfrd_list() const
{
    int id;
    string name;
    cout << "\nFriend List of " << currentUserName << " (ID: " << currentUserID << "):" << endl;
    ifstream myfile("friend0.txt");
    if (n_friend == 0)  //if NO friend it read the file and show previous friend
    {
        if (myfile.is_open())
        {
            while (myfile)
            {
                myfile >> id;
                getline(myfile, name);
                if (id == currentUserID)
                {
                    cout << "Previous friends of : " << currentUserName << " is : " << name << "\n";

                }
            }
        }
        else
        {
            cout << "Unable to open \n";
        }
    }
    //Display Friend of current user
    for (int i = 0; i < n_friend; i++)
    {
        cout << frd_list[i] << endl;
    }
}
void  User::new_post()
{
    if (no_posts >= 10)
    {
        cout << "Limit of 10 posts reached! ,You Cannot create a new post" << endl;
    }
    posts[no_posts].new_post(no_posts + 1); //pass the id
    no_posts++;
    ofstream postFile("post.txt", ios::app);

    if (postFile.is_open())
    {
        postFile << "\nPosts of " << currentUserName << " (ID: " << currentUserID << "):" << endl;
        for (int i = 0; i < no_posts; i++)
        {
            postFile << "\nPost ID: " << posts[i].getpost_id() << endl;
            postFile << "Post Type: " << posts[i].getType() << endl;
            postFile << "details: " << posts[i].getdetails() << endl;
        }
        postFile << "------------------------" << endl;
        postFile.close();
        cout << "Data store" << endl;
    }
    else
    {
        cout << "Unable to open" << endl;
    }
}

void User::displayPosts() const
{
    cout << "\nPosts of " << currentUserName << " (ID: " << currentUserID << "):" << endl;
    if (no_posts == 0)
    {
        cout << "No posts found" << endl;
    }
    else
    {
        for (int i = 0; i < no_posts; i++)
        {
            posts[i].displayPost();
        }
    }
}

int User::getno_posts() const
{
    return no_posts;
}

void User::friendsposts() const
{
    int userId, id;
    string str, str1;
    cout << "Enter the user ID to view their friends posts: ";
    cin >> userId;
    ifstream inputFile("friends_posts.txt");
    if (inputFile.is_open())
    {
        while (inputFile)
        {
            inputFile >> str1;
            inputFile >> id;
            getline(inputFile, str); //input post
            if (userId == id)
            {
                cout << "\n\n\t\tFriend's Post\n";
                cout << "\n\t Name : " << str1 << ", Id : " << id << "\n";
                cout << "\t post is : '" << str << " '\n\n";
            }
        }
        inputFile.close();
    }
}

void User::addComment(int post_id, string comment)
{
    ofstream commentFile("comments.txt", ios::app);
    if (commentFile.is_open())
    {
        commentFile << currentUserID << "\t" << post_id << "\t" << comment << endl;
        commentFile.close();
        cout << "Comment added" << endl;
    }
    else
    {
        cout << "Unable to open" << endl;
    }
}

void User::Display_comments(int post_id) const
{
    cout << "\View Comments of " << currentUserName << "'s Posts (Post ID: " << post_id << "):" << endl;
    ifstream commentFile("comments.txt");
    if (commentFile.is_open())
    {
        int post;
        string user, comments;
        bool commentsFound = false;
        while (commentFile)
        {
            commentFile >> post >> user;
            getline(commentFile, comments);
            if (post == post_id)
            {
                cout << "\nUser: " << user << "\n Comments: " << comments << endl;
                commentsFound = true;
            }
        }
        commentFile.close();
        if (commentsFound == false)
        {
            cout << "No comments found for Post ID " << post_id << endl;
        }
    }
    else
    {
        cout << "unable to open" << endl;
    }
}
void User::displayTimeline() const
{
    cout << "\nTimeline of " << currentUserName << " (ID: " << currentUserID << "):" << endl;
    cout << "\t\tYour Timeline Post on ";
    GetTime();
    cout << endl << endl;

    //Post::displayPost();
    ifstream time_line("timelinesharedposts.txt");
    if (time_line.is_open())
    {
        string str;
        bool userFound = false;
        while (getline(time_line, str))
        {
            cout << str << endl;
        }
        GetTime();
        time_line.close();
    }
    else
    {
        cout << "Unable to open\n";
    }
}

void User::displayHome() const
{
    cout << "\t\t\t\t\t=== Home ===" << endl;
    cout << "Current User ID: " << currentUserID << endl;
    cout << "Current User Name: " << currentUserName << endl;
    cout << "\nFriend Posts:" << endl;
    friendsposts();
    cout << "\nYour Posts:" << endl;
    Post::displayPost();
    for (int i = 0; i < no_posts; i++)
    {
        cout << "-------------Likes and Comments--------------" << endl;
        posts[i].display_total_likes();
        Display_comments(posts[i].getpost_id());
    }
}



void User::searchPostsByKeyword(const string& keyword) const
{
    cout << "\nSearch Results for keyword '" << keyword << "':" << endl;

    for (int i = 0; i < no_posts; i++)
    {
        if (posts[i].containsKeyword(keyword) == true)
        {
            cout << "UserId: " << currentUserID << endl;
            cout << "Post Id: " << n_post << endl;
            cout << "Post Detail: " << details << endl;
        }
    }
}

bool searchUser(const string& userName) {
    ifstream userFile("users.txt");

    if (!userFile.is_open()) {
        cout << "Failed to open 'users.txt'." << endl;
        return false;
    }

    string name;
    int id;

    while (userFile >> name >> id) {
        if (name == userName) {
            cout << "User found!\n";
            cout << "ID: " << id << "\nName: " << name << endl;
            userFile.close();
            return true;
        }
    }

    cout << "User not found!\n";
    userFile.close();
    return false;
}

//// Function to search for posts containing a specific word
void searchPostsByKeyword(const string& keyword) {
    ifstream postFile("Posts.txt");

    if (!postFile.is_open()) {
        cout << "Failed to open 'post.txt'." << endl;
        return;
    }

    int post_id;
    string postType, details;

    while (postFile >> post_id >> postType) {
        // Read the rest of the line as details
        getline(postFile, details);

        // Search for the keyword in details
        size_t found = details.find(keyword);
        if (found != string::npos) {
            cout << "Post found!\n";
            cout << "Post ID: " << post_id << "\nType: " << postType << "\nDetails: " << details << endl;
        }
    }

    postFile.close();
}



int main()
{
    system("Color 06");
    cout << "\t\t\t\t       ===Social Networking Application===" << endl;
    User user;

    string name;
    int id;
    string currentUser;
    int currentUserId;
    int no_users_file = 0;

    ifstream myfile("users.txt");
    if (myfile.is_open())
    {
        cout << "\n\t\t\t\t\t\t'LIST OF USERS'" << endl;
        cout << "\n\n\t\t\t\t\tID'S \t\t\tNAME'S \n" << endl;
        while (myfile)
        {
            myfile >> name >> id;
            no_users_file++;
            cout << "\t\t\t\t\t|" << id << "|\t\t\t|" << name << "|" << endl;
        }
        myfile.close();
    }
    else
    {
        cout << "Unable to open" << endl;
        ////write users in file if file not found;
        ofstream ofile("users.txt");
        if (ofile.is_open())
        {
            int size;
            cout << "Enter No. of User You want to Enter in file" << endl;
            cin >> size;
            if (size < 0 && size>10)
            {
                cout << "Invalid Input! You Enter Maximum 10 user" << endl;
                cin >> size;
            }
            for (int i = 0; i < size; i++)
            {
                cout << "Enter Name and Id of user " << i + 1 << " : " << endl;
                cin >> name;
                ofile << name;
                ofile << "\t";
                cin >> id;
                ofile << id;
                ofile << endl;
            }
            ofile.close();
        }
    }
    cout << "\n\t\tEnter the current user ID: ";
    cin >> currentUserId;

    //check if userid is found or not.
    myfile.open("users.txt");
    if (myfile.is_open())
    {
        bool user_found = false;
        while (myfile)
        {
            myfile >> name >> id;
            if (id == currentUserId)
            {
                currentUser = name;
                user_found = true;
                break;
            }
        }
        myfile.close();
        if (user_found == false)
        {
            cout << "User not found." << endl;
        }
    }
    else
    {
        cout << "Failed to open the file." << endl;
    }
    system("cls");

    user.setCurrentUser(currentUserId, currentUser);  //SETTING THE CURRENT USER  

    int currentUserID = user.getCurrentUser();
    string currentUserName = user.getCurrentUserName();
    cout << "\n\n\nCurrent User ID: " << currentUserID << endl;
    cout << "Current User Name: " << currentUserName << endl;

    string* users_list = new string[no_users_file];
    //dynamic string that store all users name
    myfile.open("users.txt");
    int user_index = 0;
    if (myfile.is_open())
    {
        while (myfile)
        {
            myfile >> name >> id;
            users_list[user_index] = name;
            user_index++;
        }
        myfile.close();
    }
    else
    {
        cout << "Unable to open" << endl;
    }

    int ch;
    do
    {
        cout << "\n\n\t\t\t\t\tMENU\n\n\t\t\t\t1.View Friend List:\n\t\t\t\t2.Add Friends:\n\t\t\t\t3.Create Post:\n\t\t\t\t4.View Posts:\n\t\t\t\t5.View Friends Posts:\n\t\t\t\t6. Add Comment:\n\t\t\t\t7. Comments On Posts:\n\t\t\t\t8. Likes On Posts:\n\t\t\t\t9. Share post to timeline:\n\t\t\t\t10. View Timeline:\n\t\t\t\t11. View home Page:\n\t\t\t\t12. Search keyword & user \n\t\t\t\t0. Exit\n";
        cout << "Enter your choice: ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            user.displayfrd_list();
            break;
        case 2:
            int no_friend;
            cout << "Enter the number of friends you want to add: ";
            cin >> no_friend;
            user.addFriends(no_friend, users_list, no_users_file);
            cout << endl;
            user.displayfrd_list();
            break;
        case 3:

            user.new_post();
            break;
        case 4:
            user.displayPosts();
            break;
        case 5:
            user.friendsposts();
            break;
        case 6:
            int post_id;
            cout << "Enter the post ID to add a comment: ";
            cin >> post_id;
            if (post_id >= 1 && post_id <= user.getno_posts())
            {
                string comment;
                cout << "Enter your comment: ";
                cin.ignore();
                getline(cin, comment);
                user.addComment(post_id, comment);
            }
            else
            {
                cout << "Invalid post ID. Please enter a valid one" << endl;
            }
            break;
        case 7:
            int c_post_id;
            cout << "Enter the post ID to  comments: ";
            cin >> c_post_id;
            if (c_post_id >= 1 && c_post_id <= user.getno_posts())
            {
                user.Display_comments(c_post_id);
            }
            else
            {
                cout << "Invalid post ID. Please enter a valid one\t" << endl;
            }
            break;
        case 8:
            int like_id;
            cout << "Enter the post ID to display likes: ";
            cin >> like_id;

            if (like_id >= 1 && like_id <= user.getno_posts())
            {
                user.posts[like_id - 1].gettotal_likes(like_id);
                user.posts[like_id - 1].display_total_likes();
            }
            else
            {
                cout << "Invalid post ID. Please enter a valid one" << endl;
            }
            break;
        case 9:
        {
            int no_posts;
            cout << "Enter the number of posts you want to share to the timeline: ";
            cin >> no_posts;
            ofstream time_line("timelinesharedposts.txt", ios::app);
            if (time_line.is_open())
            {
                for (int i = 0; i < no_posts; i++)
                {
                    int post_id;
                    cout << "Enter the post ID to share (Post " << i + 1 << "): ";
                    cin >> post_id;
                    if (post_id >= 1 && post_id <= user.getno_posts())
                    {
                        user.posts[post_id - 1].sharePost(post_id, currentUserID, currentUserName);
                    }
                    else
                    {
                        cout << "Invalid post ID. Please enter a valid one" << endl;
                    }
                }
                time_line.close();
            }
            else
            {
                cout << "Unable to open" << endl;
                break;
            }
            break;
        }
        case 10:
            user.displayTimeline();
            break;
        case 11:

            //user.setCurrentUser(currentUserId, currentUser);
            user.displayHome();
            break;
        case 12:
            int searchChoice;
            cout << "Choose search option:\n1. Search for a user\n2. Search for posts containing a keyword\n";
            cin >> searchChoice;

            if (searchChoice == 1) {
                string userName;
                cout << "Enter the user name to search: ";
                cin >> userName;
                searchUser(userName);
            }
            else if (searchChoice == 2) {
                string keyword;
                cout << "Enter the keyword to search posts: ";
                cin >> keyword;
                user.searchPostsByKeyword(keyword);
            }
            else {
                cout << "Invalid choice!\n";
            }
            break;
        case 0:
            break;
        default:
            cout << "Invalid choice.Try Again" << endl;
        }
    } while (ch != 0);
    delete[] users_list;

    system("pause");
    return 0;
}