#include <iostream>
#include<fstream>

using namespace std;

const int MAX_FRIENDS = 10;
const int MAX_LIKEDPAGES = 10;


//-------------------------------------------------PROTOTYPES---------------------------

class helper;
class user;
class page;
class activity;
class post;
class postContent;
class controller;
class date;
class object;
class comment;


class postContent {

public:
    virtual void print() {};

};

class helper {
public:
    static int strlen(char* str);
    static void strcopy(char*& dest, char* src);
    static bool compareText(char* str1, char* str2);
};

class date {
private:
    int day;
    int month;
    int year;



public:
    date(int d = 0, int m = 0, int y = 0);
    void setDate(int d = 0, int m = 0, int y = 0);
    void print();
    void LoadDate(ifstream& fin);
    static date currentDate;

    int getDay();
    int getMonth();
    int getYear();

    bool isAMemory(date rhs);
    bool isDateWithinTwoDays(date rhs);
    bool isSame(date rhs);
};


class object {
private:
    char* Id;
protected:
    post** timeLine; 
public:
    object();
    ~object();

    void setId(char* str);
    char* getId();
    virtual void displayInfo() { ;  };
    virtual void printName() { ; };
    void viewTimeline();
    virtual void addPostToTimeline(post* p);
    void printLatestPost(date cDate);
    
    
};


class page : public object {
private:
    char* pageTitle;
public:
    page();
    ~page();
    page(const page& p1);

    void setPageTitle(char* str);
    void LoadData(ifstream& fin);

    void displayInfo() ;
    
    bool checkId(char* id);
    void displayPage();
    void printName() { cout << pageTitle; };
    
};

class user : public object {
private:
    char* FName;
    char* LName;
    int friendCount, likedPagesCount;
    user** friendList;
    page** likedPages;
public:
    user();
    ~user();
    user(const user& u1);

    void setFName(char* str);
    void setLName(char* str);

    char* getFname();
    char* getLName();

    void LoadData(ifstream& fin);

    void displayInfo() ;

    bool CheckId(char* Id);
    void addFriend(user*& f1);
    void likePage(page*& p1);
    void printName() { cout << FName << " " << LName; }

    void viewFriends();
    void viewLikedPages();

    void viewHome(date cDate);

    void seeMemories();
    void shareMemory(post* p, char* t);
   
};

class activity :public postContent {
private:
    int type;
    char* value;
public:
    activity(int, char*);
    //~activity();
  
    void print();
};

class post {
private:
    char* postId;
    date sharedDate;
    char* postText;
    object* sharedBy;
    object** likedBy;
    int numLikes;
    comment** commentsOnPost;
    int numComments;
    postContent* act;
    //postContent** content;

public:
    post(int day = 0, int month = 0, int year = 0);
    virtual ~post();
    void loadData(ifstream& fin);

    virtual void viewPost();
    void printPost();

    void setPostId(char* c);
    void setPostText(char* c);

    char* getPosttext();
    char* getPostId();

    bool checkId(char* c);

    void displayLikers();

    void setSharedBy(object* obj);
    void setLikedBy(object* obj);
    object* getSharedBy() { return sharedBy; };

    void addComment(comment* c);
    void addActivity(activity* a);
    date getDate();

    postContent* getActivity() { return act; }

};



class comment {
private:
    object* commentBy;
    char* text;
    char* commentId;
public:
    comment();
    ~comment();
    void setValues(object*, char*, char*);
    void print();
};



class controller {
private:
    user** AllUsers;
    page** AllPages;
    user* currentUser;
    post** AllPosts;

    static int userCount;
    static int pageCount;
    static int postCount;
public:
    controller();
    ~controller();
    void setCurrentUser(char* u);
    user* getCurrentUser();
    void setPostCount(int n);
    void setTotalUsers(int n);
    void setTotalPages(int n);

    int getTotalPages();
    int getTotalUsers();
    int getPostCount();

    void LoadAllUsers(ifstream& fin);
    void LoadAllPages(ifstream& fin);
    void LoadAllPosts(ifstream& fin);
    void LoadAllComments(ifstream& fin);
    void LoadAllActivities(ifstream& fin);

    void LoadAllData();
    void LinkUsersAndPages(ifstream& fin);

    object* FindObjById(char* c);
    user* FindUserByID(char* Id);
    page* FindPageById(char* Id);
    post* FindPostById(char* Id);
    void run();
};

class memory : public post {
private:
    post* orignalPost;
public:
    memory(post* old, char* newText);
    void viewPost();
};
//                                                                                     DEFINITIONS


//                                                           HELPER
int helper::strlen(char* str) {
    int l = 0;
    if (str)
    {
        while (str[l] != '\0')
            l++;
    }
    return l;
}
void helper::strcopy(char*& dest, char* src) {

    int len = strlen(src);
    char* str = new char[len + 1];
    for (int i = 0; i < len; i++)
    {
        str[i] = src[i];
    }
    str[len] = '\0';
    dest = str;

}
bool helper::compareText(char* str1, char* str2)
{
    int len1, len2;
    for (len1 = 0; str1[len1] != '\0'; len1++);
    for (len2 = 0; str2[len2] != '\0'; len2++);
    if (len1 == len2)
    {
        for (int i = 0; i < len1; i++)
        {
            if (str1[i] != str2[i])
                return false;
        }
        return true;
    }
    else
        return false;

}
//                                                         DATE

date::date(int d, int m, int y) : day(d), month(m), year(y) {}

void date::setDate(int d, int m, int y) {
    day = d;
    month = m;
    year = y;
}
void date::print() {
    cout << day << " / " << month << " / " << year ;
}
void date::LoadDate(ifstream& fin) {
    int d, m, y;
    fin >> d >> m >> y;
    setDate(d, m, y);
}
int date::getDay() {
    return day;
}
int date::getMonth() {
    return month;
}
int date::getYear() {
    return year;
}
bool date::isAMemory(date rhs) {
    if (day == rhs.day && month == rhs.month && year != rhs.year)
    {
        return true;
    }
    else
        return false;

}
bool date::isDateWithinTwoDays(date rhs) {
    if (((day == rhs.day) && (month == rhs.month) && (year == rhs.year)) || ((day == rhs.day + 1) && (month == rhs.month) && (year == rhs.year))) {
        return true;
    }
    else {
        return false;
    }
}
bool date::isSame(date rhs) {
    if ((day == rhs.day)&&(month==rhs.month)&&(year==rhs.year)) {
        return true;
    }
    return false;
}

//                                                         OBJECT

object::object() {
    Id = new char[100];
    Id[0] = '\0';

    timeLine = new post * [10];
    for (int i = 0;i < 10;i++) {
        timeLine[i] = nullptr;
    }
}
object::~object() {
    if (Id) {
        delete[] Id;
    }
    for (int i = 0;i < 10;i++) {
        if (timeLine[i]) {
            delete timeLine[i];
        }
    }
    delete[] timeLine;

}
void object::setId(char* str) {
    helper::strcopy(Id, str);
}
char* object::getId() {
    return Id;
}
void object::viewTimeline() {

    for (int i = 0;i < 10;i++) {
        if (timeLine[i] != nullptr) {
            timeLine[i]->viewPost();
            cout << endl;
        }
    }
}
void object::addPostToTimeline(post* p) {
    for (int i = 0;i < 10;i++) {
        if (timeLine[i] == nullptr) {
            timeLine[i] = p;
            break;
        }
    }
}
void object::printLatestPost(date cDate) {

    for (int i = 0;i < 10;i++) {
        if (timeLine[i] != nullptr) {
            if (timeLine[i]->getDate().isDateWithinTwoDays(cDate)) {
                timeLine[i]->viewPost();
            }
        }
    }
}

//                                                        PAGE

page::page() {
    pageTitle = new char[100];
    pageTitle[0] = '\0';
}
page::~page() {
    if (pageTitle) {
        delete[] pageTitle;
    }
}
page::page(const page& p1) {
    if (p1.pageTitle) {
        pageTitle = new char[helper::strlen(p1.pageTitle) + 1];
        helper::strcopy(pageTitle, p1.pageTitle);
    }
}
void page::setPageTitle(char* str) {
    helper::strcopy(pageTitle, str);
}
void page::LoadData(ifstream& fin) {
    char buffer[100];

    fin.getline(buffer, 100, '\t');
    object::setId(buffer);

    fin.getline(buffer, 100, '\n');
    setPageTitle(buffer);
}
void page::displayInfo() {
    cout << object::getId() << " - " << pageTitle << endl;
}
bool page::checkId(char* id) {
    return helper::compareText(id, object::getId());
}
void page::displayPage() {
    cout << pageTitle << endl;
    viewTimeline();
}
//                                                     USER


user::user() : friendCount(0), likedPagesCount(0), FName(new char[100]), LName(new char[100]), friendList(new user* [MAX_FRIENDS]), likedPages(new page* [MAX_LIKEDPAGES]) {
    FName[0] = '\0';
    LName[0] = '\0';
    for (int i = 0; i < MAX_FRIENDS; i++) {
        friendList[i] = nullptr;
    }
    for (int i = 0; i < MAX_LIKEDPAGES; i++) {
        likedPages[i] = nullptr;
    }
}
user::~user() {
    
    if (FName) {
        delete[] FName;
    }
    if (LName) {
        delete[] LName;
    }
    if (friendList) {
        delete[] friendList;
    }
    if (likedPages) {
        delete[] likedPages;
    }

}
user::user(const user& u1) {
    if (u1.FName) {
        FName = new char[helper::strlen(u1.FName) + 1];
        helper::strcopy(FName, u1.FName);
    }
    if (u1.LName) {
        LName = new char[helper::strlen(u1.LName) + 1];
        helper::strcopy(LName, u1.LName);
    }
    friendCount = u1.friendCount;
    likedPagesCount = u1.likedPagesCount;
    for (int i = 0; i < MAX_FRIENDS; i++) {
        if (u1.friendList[i]) {
            friendList[i] = new user(*u1.friendList[i]);
        }
        else {
            friendList[i] = nullptr;
        }
    }
    for (int i = 0; i < MAX_LIKEDPAGES; i++) {
        if (u1.likedPages[i]) {
            likedPages[i] = new page(*u1.likedPages[i]);
        }
        else {
            likedPages[i] = nullptr;
        }
    }
}
void user::setFName(char* str) {
    helper::strcopy(FName, str);
}
void user::setLName(char* str) {
    helper::strcopy(LName, str);
}
char* user::getFname() {
    return FName;
}
char* user::getLName() {
    return LName;
}
void user::LoadData(ifstream& fin) {
    char buffer[80];
    fin >> buffer;
    object::setId(buffer);
    fin >> buffer;
    setFName(buffer);
    fin >> buffer;
    setLName(buffer);
}
void user::displayInfo() {
    cout << object::getId() << "  " << FName << " " << LName << endl;
}
bool user::CheckId(char* Id) {
    return helper::compareText(Id, object::getId());
}
void user::addFriend(user*& f1) {
    for (int i = 0; i < MAX_FRIENDS; i++) {
        if (friendList[i] == nullptr) {
            friendList[i] = f1;
            friendCount++;
            break;
        }
    }
}
void user::likePage(page*& p1) {
    for (int i = 0; i < MAX_LIKEDPAGES; i++) {
        if (likedPages[i] == nullptr) {
            likedPages[i] = p1;
            likedPagesCount++;
            break;
        }
    }
}
void user::viewFriends() {
    cout << "Friends of " << FName << " " << LName << " (" << object::getId() << ") are:" << endl << endl;
    for (int i = 0; i < friendCount; i++) {

        friendList[i]->displayInfo();
    }
    cout << endl;
}
void user::viewLikedPages() {
    cout << "Liked Pages of  " << FName << " " << LName << "( " << object::getId() << " ) are:" << endl << endl;
    for (int i = 0; i < likedPagesCount; i++) {

        likedPages[i]->displayInfo();
    }
    cout << endl << endl;
}
void user::viewHome(date cDate) {

    cout << "Home page of " << FName << " " << LName << endl << endl;

    printLatestPost(cDate);

    for (int i = 0;i < friendCount;i++) {
        friendList[i]->printLatestPost(cDate);

    }
    for (int i = 0;i < likedPagesCount;i++) {
        likedPages[i]->printLatestPost(cDate);
    }
}
void user::seeMemories()
{
   
    for (int i = 0; i < 10; i++)
    {
        if (timeLine[i]) {
            if (date::currentDate.isAMemory(timeLine[i]->getDate()))
            {
                cout << date::currentDate.getYear() - timeLine[i]->getDate().getYear() << " Years Ago\n";
                timeLine[i]->viewPost();
            }

        }

    }
}
void user::shareMemory(post* p, char* t)
{
    for (int i = 0;i < 10;i++) {
        if (timeLine[i] == nullptr) {
            timeLine[i] = new memory(p, t);
            break;
        }
    }
    
}




//                                                             CONTROLLER
int controller::pageCount = 0;
int controller::userCount = 0;
int controller::postCount = 0;
date date::currentDate=date(17,4,2024);



controller::controller() : AllUsers(nullptr), AllPages(nullptr), currentUser(nullptr), AllPosts(nullptr) {}

controller::~controller() {
    for (int i = 0; i < userCount; i++) {
        delete AllUsers[i];
    }
    delete[] AllUsers;
    for (int i = 0; i < pageCount; i++) {
        delete AllPages[i];
    }
    delete[] AllPages;

}
void controller::setCurrentUser(char* u) {
    user* temp = FindUserByID(u);
    currentUser = temp;
    cout << temp->getFname() << " " << temp->getLName() << " successfully set as Current User\n-------------------------------------------------------------------------------------------------------------" << endl;
    
}
user* controller::getCurrentUser() {
    return currentUser;
}
void controller::setPostCount(int n) {
    postCount = n;
}
void controller::setTotalUsers(int n) {
    userCount = n;
}
void controller::setTotalPages(int n) {
    pageCount = n;
}
int controller::getTotalPages() {
    return pageCount;
}
int controller::getTotalUsers() {
    return userCount;
}
int controller::getPostCount() {
    return postCount;
}
user* controller::FindUserByID(char* Id) {
    // cout << "in find userby id"<<endl;
    for (int i = 0; i < getTotalUsers(); i++) {
        if (AllUsers[i]->CheckId(Id)) {
            return AllUsers[i];
        }
    }
    return nullptr;
}
page* controller::FindPageById(char* Id) {
    //cout << "in find page by id " << endl;
    for (int i = 0; i < getTotalPages(); i++) {
        if (AllPages[i]->checkId(Id)) {
            return AllPages[i];
        }
    }
    return nullptr;
}
post* controller::FindPostById(char* Id) {
    for (int i = 0; i < getPostCount(); i++) {
        if (AllPosts[i]->checkId(Id)) {
            return AllPosts[i];
        }
    }
    return nullptr;
}
void controller::LoadAllUsers(ifstream& fin) {
    //cout << "in load all users" << endl;
    int n;
    fin >> n;
    setTotalUsers(n);

    AllUsers = new user * [getTotalUsers()];
    for (int i = 0; i < getTotalUsers(); i++) {
        AllUsers[i] = new user();
        AllUsers[i]->LoadData(fin);
    }
}
void controller::LoadAllPages(ifstream& fin) {

    int k;
    fin >> k;
    setTotalPages(k);
    fin.ignore(numeric_limits<streamsize>::max(), '\n');
    AllPages = new page * [getTotalPages()];

    for (int i = 0; i < getTotalPages(); i++) {
        AllPages[i] = new page();
        AllPages[i]->LoadData(fin);
    }
}
void controller::LoadAllPosts(ifstream& fin) {
    //cout << "in load all posts" << endl;

    int n;
    fin >> n;
    setPostCount(n);
    AllPosts = new post * [getPostCount()];
    char  end[3] = "-1";
    fin.ignore();
    char buffer[100];

    for (int i = 0; i < getPostCount(); i++) {

        AllPosts[i] = new post();
        AllPosts[i]->loadData(fin);
        fin >> buffer;

        object* obj = FindObjById(buffer);
        AllPosts[i]->setSharedBy(obj);
        fin >> buffer;


        while (!helper::compareText(end, buffer)) {
            object* obj2 = FindObjById(buffer);
            AllPosts[i]->setLikedBy(obj2);
            fin >> buffer;

        }

        obj->addPostToTimeline(AllPosts[i]);

        fin.ignore();

    }
}
void controller::LoadAllComments(ifstream& fin) {
    int n;
    fin >> n;
 

    for (int i = 0;i < n;i++) {

        comment* temp = new comment();

        char commentId[10];
        char postId[10];
        char commenterId[10];
        char commentText[200];

        fin >> commentId >> postId >> commenterId;
        fin.getline(commentText, 200);

        object* obj = FindObjById(commenterId);

        temp->setValues(obj, commentText, commentId);

        post* p = FindPostById(postId);


        p->addComment(temp);
        //p->displayPost();

    }
}
void controller::LoadAllActivities(ifstream& fin) {

    int totalActivities, bufferType;
    char bufferid[10], bufferText[80];
    post* activityOn;

    fin >> totalActivities;
    for (int i = 0; i < totalActivities; i++)
    {
        fin >> bufferid;
        activityOn = FindPostById(bufferid);
        fin >> bufferType;
        fin.getline(bufferText, 79);
        activity* activityBuffer = new activity(bufferType, bufferText);
        activityOn->addActivity(activityBuffer);
        //activityOn->setPostContent(activityBuffer);
       
        
    }
   
}
void controller::LoadAllData() {

    ifstream myFile("SocialNetworkUsers.txt");
    if (!myFile.is_open()) {
        cout << "File opening error" << endl;
    }
    ifstream myFile2("SocialNetworkPages.txt");
    if (!myFile2.is_open()) {
        cout << "File opening error" << endl;
    }
    ifstream myFile3("UsersFriendsAndLikedPages.txt");
    if (!myFile3.is_open()) {
        cout << "File opening error" << endl;
    }
    ifstream myFile4("SocialNetworkPosts.txt");
    if (!myFile4.is_open()) {
        cout << "File opening error" << endl;
    }
    ifstream myFile5("SocialNetworkComments.txt");
    if (!myFile5.is_open()) {
        cout << "File opening error" << endl;
    }
    ifstream myFile6("SocialNetworkActivities.txt");
    if (!myFile6.is_open()) {
        cout << "File opening error" << endl;
    }

    LoadAllUsers(myFile);
    LoadAllPages(myFile2);
    LinkUsersAndPages(myFile3);
    LoadAllPosts(myFile4);
    LoadAllComments(myFile5);
    LoadAllActivities(myFile6);
}
void controller::LinkUsersAndPages(ifstream& fin) {

    char buffer[5];
    fin >> buffer;

    char end[3];
    end[0] = '-';
    end[1] = '1';
    end[2] = '\0';

    while (!helper::compareText(buffer, end)) {
        user* temp = FindUserByID(buffer);
        fin >> buffer;
        while (!helper::compareText(buffer, end)) {
            user* friendToAdd = FindUserByID(buffer);
            if (friendToAdd != nullptr) {
                temp->addFriend(friendToAdd);
            }
            fin >> buffer;
        }

        fin >> buffer;
        while (!helper::compareText(buffer, end)) {
            page* pageToLike = FindPageById(buffer);
            if (pageToLike != nullptr) {
                temp->likePage(pageToLike);
            }
            fin >> buffer;
        }

        fin >> buffer;
    }
}
object* controller::FindObjById(char* c) {

    switch (c[0]) {
    case'u':
    case'U':
        return FindUserByID(c);
    case 'p':
    case 'P':
        return FindPageById(c);
    default:
        return nullptr;
    }
}
void controller::run() {

    cout << "Command:                Set current System Date 17 4 2024\n-------------------------------------------------------------------------------------------------------------" << endl;
    //1-Set current date;
    date currentDate;
    currentDate.setDate(17, 4, 2024);


    char n[] = "u7";                                //2-Set Current User
    cout << "Command:                Set current user (u7)" << endl << endl;
    setCurrentUser(n);
    user* temp = getCurrentUser();

    cout << "Command:                View Friend List \n-------------------------------------------------------------------------------------------------------------" << endl;
    temp->viewFriends();                             //3-View Friend List

    cout << "Comand:                  View Liked Pages\n-------------------------------------------------------------------------------------------------------------" << endl;
    temp->viewLikedPages();                          //4- View Liked Pages

    cout << "Command:                  View TimeLine\n-------------------------------------------------------------------------------------------------------------" << endl;
    temp->viewTimeline();

    char postId[] = "post5";                         //5-Like a post
    post* p1 = FindPostById(postId);
    cout << "Command:                   ViewLikedList(post5)\n-------------------------------------------------------------------------------------------------------------" << endl;
    p1->displayLikers();                             //6-View the list of People who liked a post

    cout << "Command:                   LikePost(post5)\n-------------------------------------------------------------------------------------------------------------" << endl;
    p1->setLikedBy(temp);                            //7- like a post

    cout << "Command:                   ViewLikedList(post5)\n-------------------------------------------------------------------------------------------------------------" << endl;
    p1->displayLikers();                             //8-View the list of People who liked a post

    char p[] = "p1";                                 //9-View Page and its posts
    cout << "Command:                   ViewPage(p1)\n-------------------------------------------------------------------------------------------------------------" << endl;
    page* page1 = FindPageById(p);
    page1->displayPage();

    cout << "Command:                   View Home\n-------------------------------------------------------------------------------------------------------------" << endl;
    temp->viewHome(currentDate);                              //10- View user's home

    cout << "Command:                   PostComment(post4, Good Luck for your Result)\n-------------------------------------------------------------------------------------------------------------" << endl;
    char post4[] = "post4";
    post* p4 = FindPostById(post4);              //11-Post a comment on a post

    char text[] = "Good Luck for your Result";
    comment* newComment = new comment();
    newComment->setValues(temp, text, 0);
    p4->addComment(newComment);


    cout<<"Command:                   ViewPost(post4)\n-------------------------------------------------------------------------------------------------------------" << endl;
    p4->viewPost();                  //12- display that post

    cout << "Command:                   PostComment(post8, Thanks for the wishes)\n-------------------------------------------------------------------------------------------------------------" << endl;
    char post8[] = "post8";
    post* p8 = FindPostById(post8);                 //11-Post a comment on a post

    char text2[] = "Thanks for the wishes";
    comment* newComment2 = new comment();
    newComment2->setValues(temp, text2, 0);
    p8->addComment(newComment2);

    cout << "Command:                   ViewPost(post8)\n-------------------------------------------------------------------------------------------------------------" << endl;
    p8->viewPost();                             //12- display that post

    cout<<"Command:                   SeeYourMemories()\n-------------------------------------------------------------------------------------------------------------" << endl;
    cout << "We hope you enjoy looking back and sharing your memories on Facebook, from the most recent to those long ago.\n\n";
    temp->seeMemories();

    char bufferID[10] = "post10";
    char bufferText[80] = "Never thought i will be specialist in this field.";
    post* memoryAddPost = FindPostById(bufferID);
    temp->shareMemory(memoryAddPost, bufferText);


    cout<<"Command:                  View TimeLine\n-------------------------------------------------------------------------------------------------------------" << endl;
    temp->viewTimeline();                         //15 - view timeline after adding comment and new memory, modify timeline function to include memories as well

    //char m[] = "u11";                               // 16- Change user
    //cout << "Command:                Set current user (u11)\n-------------------------------------------------------------------------------------------------------------" << endl;
    //setCurrentUser(m);
    //user* temp2 = getCurrentUser();
    //temp2->displayInfo();

    //////16- set different currecnt date 
    //currentDate.setDate(10, 9, 2010);


 

}
//                                                            POST 

post::post(int day, int month, int year) : act(nullptr), sharedBy(nullptr), likedBy(new object* [10]), numLikes(0), commentsOnPost(new comment* [10]), numComments(0) {

    postId = new char[20];
    postId[0] = '\0';

    postText = new char[200];
    postText[0] = '\0';

    sharedDate = date(day, month, year);
    sharedBy = nullptr;
    act = nullptr;

    /*content = new postContent * ();
    content[0] = nullptr;*/


    for (int i = 0; i < MAX_FRIENDS; ++i) {
        likedBy[i] = nullptr;
    }
    for (int i = 0;i < 10;i++) {
        commentsOnPost[i] = nullptr;
    }
}
date post::getDate() {
    return sharedDate;
}
post::~post() {
    if (postId) {
        delete[] postId;
    }
    if (postText) {
        delete[] postText;
    }
    if (likedBy) {
        delete[] likedBy;
    }
    for (int i = 0; i < 10; i++)
    {
        if (commentsOnPost[i]) {
            delete commentsOnPost[i];
        }
       
    }
    delete[] commentsOnPost;
    /*if (content[0])
        delete[] content[0];*/

   // delete[] content;

    delete act;

}
void post::setPostId(char* c) {

    postId = new char[helper::strlen(c) + 1];
    helper::strcopy(postId, c);
}
void post::setPostText(char* c) {

    postText = new char[helper::strlen(c) + 1];
    helper::strcopy(postText, c);
}
char* post::getPosttext() {
    return postText;
}
char* post::getPostId() {
    return postId;
}
void post::loadData(ifstream& fin) {


    char postId[100];
    fin.getline(postId, 100);
    setPostId(postId);

    sharedDate.LoadDate(fin);
    fin.ignore();


    char postText[1000];
    fin.getline(postText, 1000);
    setPostText(postText);
}
void post::displayLikers() {
    cout << endl << "Liked By: " << endl << endl;
    for (int i = 0; i < numLikes; ++i) {
        cout << " ";
        likedBy[i]->displayInfo();
        cout << endl;
    }
    cout << endl;
}
void post::setSharedBy(object* obj) {
    if (sharedBy == nullptr) {
        sharedBy = obj;
    }
}
void post::addActivity(activity* a) {
    if (act == nullptr) {
        act = a;
    }
}
void post::setLikedBy(object* obj) {
    for (int i = 0;i < 10;i++) {
        if (likedBy[i] == nullptr) {
            likedBy[i] = obj;
            numLikes++;
            break;
        }
    }
}
bool post::checkId(char* c) {
    return helper::compareText(c, post::getPostId());
}
void post::addComment(comment* c) {
    if (c == nullptr) {
        cout << "Error: Attempted to add a null comment." << endl;
        return;
    }

    for (int i = 0; i < 10; i++) {
        if (commentsOnPost[i] == nullptr) {
            commentsOnPost[i] = c;
            return;
        }
    }

    cout << "Error: The commentsOnPost array is full. Comment not added." << endl;
}
void post::viewPost()
{
    cout << "--- ";
    sharedBy->printName();
    if (act)
        act->print();
    cout << " (";
    date currentDate;
    currentDate.setDate(17, 4, 2024);
    if (sharedDate.isSame(currentDate)) {
        cout << "1hr" ;
    }
    else {
        sharedDate.print();
    }
    cout << ")";
    cout << endl << "\t\"";
    cout << postText;
    cout << ".\"";
    cout << endl;
    for (int i = 0; i < 10; i++)
    {
        if (commentsOnPost[i])
        {
            cout << "\t\t";
            commentsOnPost[i]->print();
        }
    }
}
void post::printPost()
{
    cout << postId << " shared by ";
    sharedBy->displayInfo();
}




//----------------------------------------------------------COMMENT--------------------------------------
comment::comment() {
    commentBy = nullptr;
    text = new char[200];
    commentId = new char[10];
}
comment::~comment() {
    /*if (text)
        delete[] text;*/
    /*if (commentId)
        delete[] text;*/
}
void comment::setValues(object* a, char* t, char* c) {

    helper::strcopy(text, t);
    helper::strcopy(commentId, c);

    commentBy = a;
}
void comment::print() {
    commentBy->displayInfo();

    cout << text << endl;
}

//----------------------------------------------ACTIVITY--------------------------
activity::activity(int i, char* t) {

    value = new char[100];
    type = i;
    helper::strcopy(value, t);
}
//activity::~activity() {
//    /*if (value) {
//        delete[] value;
//    }*/
//}
void activity::print() { 
    cout << " is ";

    if (type == 1) {
        cout << "Feeling " << value ;
    }
    else if (type == 2) {
        cout << "Thinking about " << value ;
    }
    else if (type == 3) {
        cout << "Making " << value ;
    }
    else if (type == 4) {
        cout << "Celebrating " << value ;
    }
}

//----------------------------------------------MEMORY-------------------------------
void memory::viewPost()
{
    cout << "---";
    orignalPost->getSharedBy()->printName();
    cout << " shared a memory---(";
    date::currentDate.print();
    cout << ")\n\t";

    cout << getPosttext() << endl;

    int yearsPassed = 0;
    yearsPassed = (date::currentDate.getYear()) - (orignalPost->getDate().getYear());
    cout << "\t----" << yearsPassed << " Years Ago----\n";
    cout << "------------------------------------------------------------------\n";
    cout << "---";
    orignalPost->getSharedBy()->printName();
    if (orignalPost->getActivity())
        orignalPost->getActivity()->print();
    cout << "(";
    orignalPost->getDate().print();
    cout << ")\n\t";
    cout << orignalPost->getPosttext() << endl;
}
memory::memory(post* old, char* newText)
{
    orignalPost = old;
    setPostText(newText);
}





int main() {
    {
        controller mainApp;
        mainApp.LoadAllData();
        mainApp.run();
    }
    _CrtDumpMemoryLeaks();

    return 0;

}
