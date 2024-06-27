//#include <iostream>
//#include<fstream>
//
//using namespace std;
//
//const int MAX_FRIENDS = 10;
//const int MAX_LIKEDPAGES = 10;
//
//
////-------------------------------------------------PROTOTYPES---------------------------
//
//
//
//class postContent {
//
//public:
//    virtual void print() {};
//
//};
//
//class helper {
//public:
//    static int strlen(char* str);
//    static void strcopy(char*& dest, char* src);
//    static bool compareText(char* str1, char* str2);
//};
//
//class date {
//private:
//    int day;
//    int month;
//    int year;
//public:
//    date(int d = 0, int m = 0, int y = 0);
//    void setDate(int d = 0, int m = 0, int y = 0);
//    void print();
//    void LoadDate(ifstream& fin);
//    static date currentDate;
//
//    int getDay();
//    int getMonth();
//    int getYear();
//
//    bool isAMemory(date rhs);
//    bool isDateWithinTwoDays(date rhs);
//};
//
//class post;
//
//class object {
//private:
//    char* Id;
//protected:
//    post** timeLine; //RECENT CHANGE 
//public:
//    object();
//    ~object();
//
//    void setId(char* str);
//    char* getId();
//    virtual void displayInfo() = 0;
//    void viewTimeline();
//    virtual void addPostToTimeline(post* p);
//    void printLatestPost(date cDate);
//};
//
//
//class page : public object {
//private:
//    char* pageTitle;
//public:
//    page();
//    ~page();
//    page(const page& p1);
//
//    void setPageTitle(char* str);
//    void LoadData(ifstream& fin);
//    void displayInfo() override;
//    bool checkId(char* id);
//    void displayPage();
//};
//
//class user : public object {
//private:
//    char* FName;
//    char* LName;
//    int friendCount, likedPagesCount;
//    user** friendList;
//    page** likedPages;
//public:
//    user();
//    ~user();
//    user(const user& u1);
//
//    void setFName(char* str);
//    void setLName(char* str);
//
//    char* getFname();
//    char* getLName();
//
//    void LoadData(ifstream& fin);
//
//    void displayInfo() override;
//    bool CheckId(char* Id);
//    void addFriend(user*& f1);
//    void likePage(page*& p1);
//
//    void viewFriends();
//    void viewLikedPages();
//
//    void viewHome(date cDate);
//    void viewMemory();
//
//};
//class comment;
//
//class activity;
//
//class post {
//private:
//    char* postId;
//    date sharedDate;
//    char* postText;
//    object* sharedBy;
//    object** likedBy;
//    object** tags;
//    int numLikes;
//    comment** commentsOnPost;
//    int numComments;
//    activity* act;
//    postContent** content;
//
//public:
//    virtual void displayInfo();
//    post(int day = 0, int month = 0, int year = 0);
//    virtual ~post();
//
//    void setPostId(char* c);
//    void setPostText(char* c);
//
//    char* getPosttext();
//    char* getPostId();
//    bool checkId(char* c);
//
//    void loadData(ifstream& fin);
//
//    void displayPost();
//    void displayLikers();
//
//    void setSharedBy(object* obj);
//    void setLikedBy(object* obj);
//    object* getSharedBy() { return sharedBy; };
//
//    void addComment(comment* c);
//    void addActivity(activity* a);
//    date getDate();
//
//    void setPostContent(activity* ptr) { content[0] = ptr; }
//    postContent* getPostContent() { return content[0]; }
//    
//};
//class memory : public post {
//private:
//    post* originalPost;
//public:
//    memory(post* old, char* newText);
//    void viewPost();
//
//
//
//    //~memory();
//
//};
//
//class comment {
//private:
//    object* commentBy;
//    char* text;
//    char* commentId;
//public:
//    comment();
//    comment(char*, object*, char*, char*);
//    ~comment();
//    void setValues(object*, char*, char*);
//
//    void print();
//};
//
//class activity:public postContent {
//private:
//    int type;
//    char* value;
//public:
//    activity();
//    ~activity();
//    void setValues(int, char*);
//    void print();
//};
//
//class controller {
//private:
//    user** AllUsers;
//    page** AllPages;
//    user* currentUser;
//    post** AllPosts;
//    comment** AllComments;
//    activity** AllActivities;
//    
//    static int userCount;
//    static int pageCount;
//    static int postCount;
//    static int commentCount;
//    static int activityCount;
//public:
//    controller();
//    ~controller();
//    void setCurrentUser(char* u);
//    user* getCurrentUser();
//    void setPostCount(int n);
//    void setTotalUsers(int n);
//    void setTotalPages(int n);
//    void setActivitiesCount(int n);
//    void setCommentCount(int n);
//
//    int getTotalPages();
//    int getTotalUsers();
//    int getPostCount();
//    int getActivitiesCount();
//    int getCommentCount();
//
//    void LoadAllUsers(ifstream& fin);
//    void LoadAllPages(ifstream& fin);
//    void LoadAllPosts(ifstream& fin);
//    void LoadAllComments(ifstream& fin);
//    void LoadAllActivities(ifstream& fin);
//
//    void LoadAllData();
//    void LinkUsersAndPages(ifstream& fin);
//
//    object* FindObjById(char* c);
//    user* FindUserByID(char* Id);
//    page* FindPageById(char* Id);
//    post* FindPostById(char* Id);
//    void run();
//};
////                                                                                     DEFINITIONS
//
//
////                                                           HELPER
//int helper::strlen(char* str) {
//    int l = 0;
//    if (str)
//    {
//        while (str[l] != '\0')
//            l++;
//    }
//    
//    return l;
//}
//void helper::strcopy(char*& dest, char* src) {
//
//    int len = strlen(src);
//    char* str = new char[len + 1];
//    for (int i = 0; i < len; i++)
//    {
//        str[i] = src[i];
//    }
//    str[len] = '\0';
//    dest = str;
//
//}
//bool helper::compareText(char* str1, char* str2)
//{
//    int len1, len2;
//    for (len1 = 0; str1[len1] != '\0'; len1++);
//    for (len2 = 0; str2[len2] != '\0'; len2++);
//    if (len1 == len2)
//    {
//        for (int i = 0; i < len1; i++)
//        {
//            if (str1[i] != str2[i])
//                return false;
//        }
//        return true;
//    }
//    else
//        return false;
//
//}
////                                                         DATE
//
//date::date(int d, int m, int y) : day(d), month(m), year(y) {}
//
//void date::setDate(int d, int m, int y) {
//    day = d;
//    month = m;
//    year = y;
//}
//void date::print() {
//    cout << day << " / " << month << " / " << year << endl;
//}
//void date::LoadDate(ifstream& fin) {
//    int d, m, y;
//    fin >> d >> m >> y;
//    setDate(d, m, y);
//}
//int date::getDay() {
//    return day;
//}
//int date::getMonth() {
//    return month;
//}
//int date::getYear() {
//    return year;
//}
//bool date::isAMemory(date rhs) {
//    if (day == rhs.day && month == rhs.month && year != rhs.year)
//    {
//        return true;
//    }
//    else
//        return false;
//
//}
//bool date::isDateWithinTwoDays(date rhs) {
//    if (((day == rhs.day) && (month == rhs.month) && (year == rhs.year)) || ((day == rhs.day + 1) && (month == rhs.month) && (year == rhs.year))) {
//        return true;
//    }
//    else {
//        return false;
//    }
//}
//
////                                                         OBJECT
//
//object::object() {
//    Id = new char[100];
//    Id[0] = '\0';
//
//    timeLine = new post * [10];
//    for (int i = 0;i < 10;i++) {
//        timeLine[i] = nullptr;
//    }
//}
//object::~object() {
//    if (Id) {
//        delete[] Id;
//    }
//}
//void object::setId(char* str) {
//    helper::strcopy(Id, str);
//}
//char* object::getId() {
//    return Id;
//}
//void object::displayInfo() {
//   
//    //cout << "in object display info" << endl;
//    // Implement displayInfo()
//    
//}
//void object::viewTimeline() {
//    //print activity
//    //print post text
//    
//    
//    for (int i = 0;i < 10;i++) {
//        if (timeLine[i] != nullptr) {
//            timeLine[i]->displayInfo();
//            cout << endl;
//        }
//    }
//}
//void object::addPostToTimeline(post* p) {
//    for (int i = 0;i < 10;i++) {
//        if (timeLine[i] == nullptr) {
//            timeLine[i] = p;
//            break;
//        }
//    }
//}
//void object::printLatestPost(date cDate) {
//
//    for (int i = 0;i < 10;i++) {
//        if (timeLine[i]->getDate().isDateWithinTwoDays(cDate)) {
//            timeLine[i]->displayPost();
//        }
//    }
//}
//
////                                                        PAGE
//
//page::page() {
//    pageTitle = new char[100];
//    pageTitle[0] = '\0';
//}
//page::~page() {
//    if (pageTitle) {
//        delete[] pageTitle;
//    }
//}
//page::page(const page& p1) {
//    if (p1.pageTitle) {
//        pageTitle = new char[helper::strlen(p1.pageTitle) + 1];
//        helper::strcopy(pageTitle, p1.pageTitle);
//    }
//}
//void page::setPageTitle(char* str) {
//    helper::strcopy(pageTitle, str);
//}
//void page::LoadData(ifstream& fin) {
//    char buffer[100];
//
//    fin.getline(buffer, 100, '\t');
//    object::setId(buffer);
//
//    fin.getline(buffer, 100, '\n');
//    setPageTitle(buffer);
//}
//void page::displayInfo() {
//    cout << object::getId() << " - " << pageTitle << endl;
//    viewTimeline();
//    
//}
//bool page::checkId(char* id) {
//    return helper::compareText(id, object::getId());
//}
//void page::displayPage() {
//    cout << pageTitle << endl;
//    viewTimeline();
//}
////                                                     USER
//
//
//user::user() : friendCount(0), likedPagesCount(0), FName(new char[100]), LName(new char[100]), friendList(new user* [MAX_FRIENDS]), likedPages(new page* [MAX_LIKEDPAGES]) {
//    FName[0] = '\0';
//    LName[0] = '\0';
//    for (int i = 0; i < MAX_FRIENDS; i++) {
//        friendList[i] = nullptr;
//    }
//    for (int i = 0; i < MAX_LIKEDPAGES; i++) {
//        likedPages[i] = nullptr;
//    }
//}
//user::~user() {
//    if (FName) {
//        delete[] FName;
//    }
//    if (LName) {
//        delete[] LName;
//    }
//}
//user::user(const user& u1) {
//    if (u1.FName) {
//        FName = new char[helper::strlen(u1.FName) + 1];
//        helper::strcopy(FName, u1.FName);
//    }
//    if (u1.LName) {
//        LName = new char[helper::strlen(u1.LName) + 1];
//        helper::strcopy(LName, u1.LName);
//    }
//    friendCount = u1.friendCount;
//    likedPagesCount = u1.likedPagesCount;
//    for (int i = 0; i < MAX_FRIENDS; i++) {
//        if (u1.friendList[i]) {
//            friendList[i] = new user(*u1.friendList[i]);
//        }
//        else {
//            friendList[i] = nullptr;
//        }
//    }
//    for (int i = 0; i < MAX_LIKEDPAGES; i++) {
//        if (u1.likedPages[i]) {
//            likedPages[i] = new page(*u1.likedPages[i]);
//        }
//        else {
//            likedPages[i] = nullptr;
//        }
//    }
//}
//void user::setFName(char* str) {
//    helper::strcopy(FName, str);
//}
//void user::setLName(char* str) {
//    helper::strcopy(LName, str);
//}
//char* user::getFname() {
//    return FName;
//}
//char* user::getLName() {
//    return LName;
//}
//void user::LoadData(ifstream& fin) {
//    char buffer[80];
//    fin >> buffer;
//    object::setId(buffer);
//    fin >> buffer;
//    setFName(buffer);
//    fin >> buffer;
//    setLName(buffer);
//}
//void user::displayInfo() {
//    cout << object::getId() << "  " << FName << " " << LName << endl;
//}
//bool user::CheckId(char* Id) {
//    return helper::compareText(Id, object::getId());
//}
//void user::addFriend(user*& f1) {
//    for (int i = 0; i < MAX_FRIENDS; i++) {
//        if (friendList[i] == nullptr) {
//            friendList[i] = f1;
//            friendCount++;
//            break;
//        }
//    }
//}
//void user::likePage(page*& p1) {
//    for (int i = 0; i < MAX_LIKEDPAGES; i++) {
//        if (likedPages[i] == nullptr) {
//            likedPages[i] = p1;
//            likedPagesCount++;
//            break;
//        }
//    }
//}
//void user::viewFriends() {
//    cout << "Friends of " << FName << " " << LName << " (" << object::getId() << ") are:" << endl << endl;
//    for (int i = 0; i < friendCount; i++) {
//        
//        friendList[i]->displayInfo();
//    }
//    cout << endl;
//}
//void user::viewLikedPages() {
//    cout << "Liked Pages of  " << FName << " " << LName << "( " << object::getId() << " ) are:" << endl << endl;
//    for (int i = 0; i < likedPagesCount; i++) {
//        
//        likedPages[i]->displayInfo();
//    }
//    cout << endl<<endl;
//}
//void user::viewHome(date cDate) {
//
//    cout << "Home page of " << FName << " " << LName << endl << endl;
//
//    printLatestPost(cDate);
//
//    for (int i = 0;i < friendCount;i++) {
//        friendList[i]->printLatestPost(cDate);
//
//    }
//    for (int i = 0;i < likedPagesCount;i++) {
//        likedPages[i]->printLatestPost(cDate);
//    }
//
//    
//
//}
//void user::viewMemory() {
//    cout << "Command:                   SeeYourMemories() " << endl;
//    cout << "We hope you enjoy looking back and sharing your memories on Facebook, from the most recent to those long ago." << endl << endl;
//
//    for (int i = 0; i < 10; i++)
//    {
//        if (date::currentDate.isAMemory(timeLine[i]->getDate()))
//        {
//            cout << date::currentDate.getYear() - timeLine[i]->getDate().getYear() << " Years Ago\n";
//            timeLine[i]->displayPost();
//        }
//    }
//   
//}
////                                                             CONTROLLER
//int controller::pageCount = 0;
//int controller::userCount = 0;
//int controller::postCount = 0;
//int controller::commentCount = 0;
//int controller::activityCount = 0;
//
//controller::controller() : AllActivities(nullptr),AllUsers(nullptr), AllPages(nullptr), currentUser(nullptr), AllPosts(nullptr),AllComments(nullptr) {}
//
//controller::~controller() {
//    for (int i = 0; i < userCount; i++) {
//        delete AllUsers[i];
//    }
//    delete[] AllUsers;
//    for (int i = 0; i < pageCount; i++) {
//        delete AllPages[i];
//    }
//    delete[] AllPages;
//}
//void controller::setCurrentUser(char* u) {
//    user* temp = FindUserByID(u);
//    currentUser = temp;
//    cout<<temp->getFname()<<" "<<temp->getLName()<<" successfully set as Current User\n-------------------------------------------------------------------------------------------------------------"<<endl;
//}
//user* controller::getCurrentUser() {
//    return currentUser;
//}
//void controller::setPostCount(int n) {
//    postCount = n;
//}
//void controller::setTotalUsers(int n) {
//    userCount = n;
//}
//void controller::setTotalPages(int n) {
//    pageCount = n;
//}
//void controller::setCommentCount(int n) {
//    commentCount = n;
//}
//void controller::setActivitiesCount(int n) {
//    activityCount = n;
//}
//int controller::getActivitiesCount() {
//    return activityCount;
//}
//int controller::getTotalPages() {
//    return pageCount;
//}
//int controller::getCommentCount() {
//    return commentCount;
//}
//int controller::getTotalUsers() {
//    return userCount;
//}
//int controller::getPostCount() {
//    return postCount;
//}
//user* controller::FindUserByID(char* Id) {
//    // cout << "in find userby id"<<endl;
//    for (int i = 0; i < getTotalUsers(); i++) {
//        if (AllUsers[i]->CheckId(Id)) {
//            return AllUsers[i];
//        }
//    }
//    return nullptr;
//}
//page* controller::FindPageById(char* Id) {
//    //cout << "in find page by id " << endl;
//    for (int i = 0; i < getTotalPages(); i++) {
//        if (AllPages[i]->checkId(Id)) {
//            return AllPages[i];
//        }
//    }
//    return nullptr;
//}
//post* controller::FindPostById(char* Id) {
//    for (int i = 0; i < getPostCount(); i++) {
//        if (AllPosts[i]->checkId(Id)) {
//            return AllPosts[i];
//        }
//    }
//    return nullptr;
//}
//void controller::LoadAllUsers(ifstream& fin) {
//    //cout << "in load all users" << endl;
//    int n;
//    fin >> n;
//    setTotalUsers(n);
//
//    AllUsers = new user * [getTotalUsers()];
//    for (int i = 0; i < getTotalUsers(); i++) {
//        AllUsers[i] = new user();
//        AllUsers[i]->LoadData(fin);
//    }
//}
//void controller::LoadAllPages(ifstream& fin) {
//
//    int k;
//    fin >> k;
//    setTotalPages(k);
//    fin.ignore(numeric_limits<streamsize>::max(), '\n');
//    AllPages = new page * [getTotalPages()];
//
//    for (int i = 0; i < getTotalPages(); i++) {
//        AllPages[i] = new page();
//        AllPages[i]->LoadData(fin);
//    }
//}
//void controller::LoadAllPosts(ifstream& fin) {
//    //cout << "in load all posts" << endl;
//
//    int n;
//    fin >> n;
//    setPostCount(n);
//    AllPosts = new post * [getPostCount()];
//    char  end[3] = "-1";
//    fin.ignore();
//    char buffer[100];
//
//    for (int i = 0; i < getPostCount(); i++) {
//
//        AllPosts[i] = new post();
//        AllPosts[i]->loadData(fin);
//        fin >> buffer;
//
//        object* obj = FindObjById(buffer);
//        AllPosts[i]->setSharedBy(obj);
//        fin >> buffer;
//        
//
//        while (!helper::compareText(end, buffer)) {
//
//
//            object* obj2 = FindObjById(buffer);
//            AllPosts[i]->setLikedBy(obj2);
//            fin >> buffer;
//
//        }
//        
//        obj->addPostToTimeline(AllPosts[i]);
//
//        fin.ignore();
//        
//    }
//}
//void controller::LoadAllComments(ifstream& fin) {
//    int n;
//    fin >> n;
//    setCommentCount(n);
//
//    AllComments = new comment * [getCommentCount()];
//
//    for (int i = 0;i < getCommentCount();i++) {
//
//        AllComments[i] = new comment();
//
//        char commentId[10];
//        char postId[10];
//        char commenterId[10];
//        char commentText[200];
//
//        fin >> commentId >> postId >> commenterId;
//        fin.getline(commentText, 200);
//
//        object* obj = FindObjById(commenterId);
//
//        AllComments[i]->setValues(obj, commentText, commentId);
//
//        post* p = FindPostById(postId);
//
//
//        p->addComment(AllComments[i]);
//
//    }
//}
//void controller::LoadAllActivities(ifstream& fin) {
//    int n;
//    fin >> n;
//    setActivitiesCount(n);
//    AllActivities = new activity * [getActivitiesCount()];
//
//
//    for (int i = 0;i < getActivitiesCount();i++) {
//        AllActivities[i] = new activity;
//
//        char pId[10];
//        int type;
//        char value[20];
//        fin >> pId >> type;
//        fin.getline(value,100);
//        AllActivities[i]->setValues(type, value);
//
//        post * p = FindPostById(pId);
//
//        p->addActivity(AllActivities[i]);
//        p->displayPost();
//    }
//}
//void controller::LoadAllData() {
//
//    ifstream myFile("SocialNetworkUsers.txt");
//    if (!myFile.is_open()) {
//        cout << "File opening error" << endl;
//    }
//    ifstream myFile2("SocialNetworkPages.txt");
//    if (!myFile2.is_open()) {
//        cout << "File opening error" << endl;
//    }
//    ifstream myFile3("UsersFriendsAndLikedPages.txt");
//    if (!myFile3.is_open()) {
//        cout << "File opening error" << endl;
//    }
//    ifstream myFile4("SocialNetworkPosts.txt");
//    if (!myFile4.is_open()) {
//        cout << "File opening error" << endl;
//    }
//    ifstream myFile5("SocialNetworkComments.txt");
//    if (!myFile5.is_open()) {
//        cout << "File opening error" << endl;
//    }
//    ifstream myFile6("SocialNetworkActivities.txt");
//    if (!myFile6.is_open()) {
//        cout << "File opening error" << endl;
//    }
//
//    LoadAllUsers(myFile);
//    LoadAllPages(myFile2);
//    LinkUsersAndPages(myFile3);
//    LoadAllPosts(myFile4);
//    LoadAllComments(myFile5);
//    LoadAllActivities(myFile6);
//}
//void controller::LinkUsersAndPages(ifstream& fin) {
//
//    char buffer[5];
//    fin >> buffer;
//
//    char end[3];
//    end[0] = '-';
//    end[1] = '1';
//    end[2] = '\0';
//
//    while (!helper::compareText(buffer, end)) {
//        user* temp = FindUserByID(buffer);
//        fin >> buffer;
//        while (!helper::compareText(buffer, end)) {
//            user* friendToAdd = FindUserByID(buffer);
//            if (friendToAdd != nullptr) {
//                temp->addFriend(friendToAdd);
//            }
//            fin >> buffer;
//        }
//
//        fin >> buffer;
//        while (!helper::compareText(buffer, end)) {
//            page* pageToLike = FindPageById(buffer);
//            if (pageToLike != nullptr) {
//                temp->likePage(pageToLike);
//            }
//            fin >> buffer;
//        }
//
//        fin >> buffer;
//    }
//}
//object* controller::FindObjById(char* c) {
//
//    //cout << "in find object by id " << endl;
//
//    switch (c[0]) {
//
//    case'u':
//    case'U':
//        return FindUserByID(c);
//    case 'p':
//    case 'P':
//        return FindPageById(c);
//    default:
//        return nullptr;
//    }
//}
//void controller::run() {
//
//    //cout << "Command:                Set current System Date 17 4 2024\n-------------------------------------------------------------------------------------------------------------" << endl;
//    //date d1;                                        //1-Set current date;
//    //d1.setDate(30, 04, 2024);
//
//    char n[] = "u7";                                //2-Set Current User
//    cout << "Command:                Set current user (u7)" << endl << endl;
//    setCurrentUser(n);
//    user* temp = getCurrentUser();
//
//    //cout << "Command:                View Friend List \n-------------------------------------------------------------------------------------------------------------" << endl;
//    //temp->viewFriends();                             //3-View Friend List
//
//    //cout << "Comand:                  View Liked Pages\n-------------------------------------------------------------------------------------------------------------" << endl;
//    //temp->viewLikedPages();                          //4- View Liked Pages
//
//    //cout << "Command:                  View TimeLine\n-------------------------------------------------------------------------------------------------------------" << endl;
//    //temp->viewTimeline();
//
//    //char postId[] = "post5";                         //5-Like a post
//    //post* p1 = FindPostById(postId);
//    //cout << "Command:                   ViewLikedList(post5)\n-------------------------------------------------------------------------------------------------------------" << endl;
//    //p1->displayLikers();                             //6-View the list of People who liked a post
//
//    //cout << "Command:                   LikePost(post5)\n-------------------------------------------------------------------------------------------------------------" << endl;
//    //p1->setLikedBy(temp);                            //7- like a post
//
//    //cout << "Command:                   ViewLikedList(post5)\n-------------------------------------------------------------------------------------------------------------" << endl;
//    //p1->displayLikers();                             //8-View the list of People who liked a post
//
//    //char p[] = "p1";                                 //9-View Page and its posts
//    //cout << "Command:                   ViewPage(p1)\n-------------------------------------------------------------------------------------------------------------" << endl;
//    //page* page1 = FindPageById(p);
//    //page1->displayPage();
//
//
//    /*cout << "Command:                   View Home\n-------------------------------------------------------------------------------------------------------------" << endl;
//    temp->viewHome();*/                              //10- View user's home
//
//    //cout << "Command:                   PostComment(post4, Good Luck for your Result)\n-------------------------------------------------------------------------------------------------------------" << endl;
//    //char post4[] = "post4";
//    //post* p4 = FindPostById(post4);              //11-Post a comment on a post
//
//    //char text[] = "Good Luck for your Result";
//    //comment* newComment = new comment();
//    //newComment->setValues(temp, text, 0);
//    //p4->addComment(newComment);
//
//
//    //cout<<"Command:                   ViewPost(post4)\n-------------------------------------------------------------------------------------------------------------" << endl;
//    //p4->displayInfo();                             //12- display that post
//
//    //cout << "Command:                   PostComment(post8, Thanks for the wishes)\n-------------------------------------------------------------------------------------------------------------" << endl;
//    //char post8[] = "post8";
//    //post* p8 = FindPostById(post8);                 //11-Post a comment on a post
// 
//    //char text2[] = "Thanks for the wishes";
//    //comment* newComment2 = new comment();
//    //newComment2->setValues(temp, text2, 0);
//    //p8->addComment(newComment2);
//
//    //cout << "Command:                   ViewPost(post8)\n-------------------------------------------------------------------------------------------------------------" << endl;
//    //p8->displayInfo();                             //12- display that post
///*
//    cout<<"Command:                   SeeYourMemories()\n-------------------------------------------------------------------------------------------------------------" << endl;
//    temp->viewMemory();   */                         //13- View user's memory
//
//    //add memory                                   //14- add a new memoery
//
//
//    //cout<<"Command:                  View TimeLine\n-------------------------------------------------------------------------------------------------------------" << endl;
//    //temp->viewTimeline();                         //15 - view timeline after adding comment and new emory, modify timeline function to include memories as well
//
//
//
//    //
//
//
//
//    //char m[] = "u11";                               // 16- Change user
//    //cout << "Command:                Set current user “u11”\n-------------------------------------------------------------------------------------------------------------" << endl;
//    //setCurrentUser(m);
//    //user* temp2 = getCurrentUser();
//    //temp2->displayInfo();
//
//    ////16- set different currecnt date 
//
//}
////                                                            POST 
//
//post::post(int day, int month, int year) : act(nullptr), sharedBy(nullptr), likedBy(new object* [10]), tags(nullptr), numLikes(0),commentsOnPost(new comment*[10]),numComments(0) {
//
//    postId = new char[20];
//    postId[0] = '\0';
//
//    postText = new char[200];
//    postText[0] = '\0';
//
//    sharedDate = date(day, month, year);
//    sharedBy = nullptr;
//    act = nullptr;
//
//
//
//
//    for (int i = 0; i < MAX_FRIENDS; ++i) {
//        likedBy[i] = nullptr;
//    }
//    for (int i = 0;i< 10;i++) {
//        commentsOnPost[i] = nullptr;
//    }
//}
//date post::getDate() {
//    return sharedDate;
//}
//post::~post() {
//    if (postId) {
//        delete[] postId;
//    }
//    if (postText) {
//        delete[] postText;
//    }
//
//    delete[] sharedBy;
//    delete[] likedBy;
//    delete[] act;
//
//}
//void post::setPostId(char* c) {
//    
//    postId = new char[helper::strlen(c) + 1];
//    helper::strcopy(postId, c);
//}
//void post::setPostText(char* c) {
//
//    postText = new char[helper::strlen(c) + 1];
//    helper::strcopy(postText, c);
//}
//char* post::getPosttext() {
//    return postText;
//}
//char* post::getPostId() {
//    return postId;
//}
//void post::loadData(ifstream& fin) {
//
//
//    char postId[100];
//    fin.getline(postId, 100);
//    setPostId(postId);
//
//    sharedDate.LoadDate(fin);
//    fin.ignore();
//
//
//    char postText[1000];
//    fin.getline(postText, 1000); // Read the Post Text
//    setPostText(postText);
//}
//void post::displayPost() {
//
//    cout << "Post ID: " << postId << endl;
//
//    cout << "Shared Date: ";
//    sharedDate.print();
//
//    cout << "Post Text: " << postText << endl;
//
//    cout << "Shared By: ";
//    if (sharedBy != nullptr) {
//        sharedBy->displayInfo();
//    }
//    else {
//        cout << "Post shared by no one";
//    }
//    cout << "Liked By: " << endl;
//
//    if (numLikes > 0) {
//        for (int i = 0; i < numLikes; ++i) {
//            cout << i + 1 << "  ";
//            likedBy[i]->displayInfo();
//            cout << endl;
//        }
//    }
//    else {
//        cout << "No one liked this post";
//    }
//    cout << endl << endl;
//    displayInfo();
//}
//void post::displayLikers() {
//    cout <<endl<< "Liked By: "<<endl<<endl;
//    for (int i = 0; i < numLikes; ++i) {
//        cout << " ";
//        likedBy[i]->displayInfo();
//        cout << endl;
//    }
//    cout << endl;
//}
//void post::displayInfo() {
//
//    if (act != nullptr) {
//        act->print();
//        cout << endl;
//    }
//    cout << postText << endl;
//    cout << "Comments:" << endl;
//    for (int i = 0;i < 10;i++) {
//        if (commentsOnPost[i] != nullptr) {
//            commentsOnPost[i]->print();
//            cout << endl;
//        }
//    }
//}
//void post::setSharedBy(object* obj) {
//    if (sharedBy == nullptr) {
//        sharedBy = obj;
//    }
//}
//void post::addActivity(activity* a) {
//    if (act == nullptr) {
//        act = a;
//    }
//}
//void post::setLikedBy(object* obj) {
//    for (int i = 0;i < 10;i++) {
//        if (likedBy[i] == nullptr) {
//            likedBy[i] = obj;
//            numLikes++;
//            break;
//        }
//    }
//}
//bool post::checkId(char* c) {
//    return helper::compareText(c, post::getPostId());
//
//}
//void post::addComment(comment* c) {
//    if (c == nullptr) {
//        cout << "Error: Attempted to add a null comment." << endl;
//        return;
//    }
//
//    for (int i = 0; i < 10; i++) {
//        if (commentsOnPost[i] == nullptr) {
//            commentsOnPost[i] = c;
//            return;  
//        }
//    }
//
//    cout << "Error: The commentsOnPost array is full. Comment not added." << endl;
//}
//
//
//
//
////----------------------------------------------------------COMMENT--------------------------------------
//comment::comment() {
//    commentBy = nullptr;
//    text = new char[200];
//    commentId = new char[10];
//}
//comment::comment(char*, object*, char*, char*) {
//
//}
//comment::~comment() {
//    if (text)
//        delete[] text;
//    if (commentId)
//        delete[] text;
//}
//void comment::setValues(object* a, char* t, char* c) {
//
//    helper::strcopy(text, t);
//    helper::strcopy(commentId, c);
//
//    commentBy = a;
//}
//void comment::print() {
//    commentBy->displayInfo();
//    cout << text << endl;
//}
//
////----------------------------------------------ACTIVITY--------------------------
//activity::activity() {
//    type = 0;
//    value = new char[100];
//}
//activity::~activity() {
//    if (value) {
//        delete[] value;
//    }
//}
//void activity::setValues(int n, char* v) {
//    helper::strcopy(value, v);
//    type = n;
//}
//void activity::print() {
//
//    if (type == 1) {
//        cout << "Feeling " << value << endl;
//    }
//    else if (type == 2){
//        cout << "Thinking about " << value << endl;
//    }
//    else if (type == 3) {
//        cout << "Making " << value << endl;
//    }
//    else if (type == 4) {
//        cout << "Celebrating " << value << endl;
//    }
//}
//
//date date::currentDate = date(17, 4, 2024);
////------------------------------------------MEMORY-------------------------------
//memory::memory(post* old, char* newText) {
//    originalPost = old;
//    setPostText(newText);
//}
//
//void memory::viewPost() {
//    cout << "---";
//    originalPost->getSharedBy()->displayInfo();
//
//    cout << " shared a memory---(";
//    date::currentDate.print();
//    cout << ")\n\t";
//
//    cout << getPosttext() << endl;
//
//    int yearsPassed = 0;
////    yearsPassed = (date::currentDate.getYear()) - (originalPost->getDate().getYear());
////    cout << "\t----" << yearsPassed << " Years Ago----\n";
////    cout << "------------------------------------------------------------------\n";
////    cout << "---";
////    originalPost->getSharedBy()->displayInfo();
////
////    if (originalPost->getPostContent())
////        originalPost->getPostContent()->print();
////    cout << "(";
////    originalPost->getDate().print();
////    cout << ")\n\t";
////    cout << originalPost->getPosttext() << endl;
////
////
////}
////
////int main() {
////
////    controller mainApp;
////    mainApp.LoadAllData();
////    mainApp.run();
////    return 0;
////
////}
////
//#include<iostream>
//#include<fstream>
//using namespace std;
//
//class Date;
//class Post;
//class User;
//class AppNetwork;
//class Helper;
//class Comment;
//class Controller;
//class PostActivity;
//class PostContent;
//class Memory;
//
//class Helper
//{
//public:
//	static int length(char* cstring)
//	{
//		int len;
//		for (len = 0; cstring[len] != '\0'; len++);
//		return len;
//	}
//	static int constlength(const char* cstring)
//	{
//		int len;
//		for (len = 0; cstring[len] != '\0'; len++);
//		return len;
//	}
//	static char* shrinkarray(char* cstring, bool deleteString = 1)
//	{
//		int len = length(cstring);
//		char* temp = new char[len + 1];
//		for (int i = 0; i < len; i++)
//		{
//			temp[i] = cstring[i];
//		}
//		temp[len] = '\0';
//		if (deleteString)
//		{
//			delete[] cstring;
//		}
//		return temp;
//	}
//	static void strcopy(const char* source, char*& dest)
//	{
//		int len = constlength(source);
//		for (int i = 0; i < len; i++)
//		{
//			dest[i] = source[i];
//		}
//		dest[len] = '\0';
//	}
//	static bool compareText(char* str1, char* str2)
//	{
//		int len1, len2;
//		for (len1 = 0; str1[len1] != '\0'; len1++);
//		for (len2 = 0; str2[len2] != '\0'; len2++);
//		if (len1 == len2)
//		{
//			for (int i = 0; i < len1; i++)
//			{
//				if (str1[i] != str2[i])
//					return false;
//			}
//			return true;
//		}
//		else
//			return false;
//
//	}
//};
//
//class Date
//{
//private:
//	int date;
//	int month;
//	int year;
//public:
//	Date();
//	~Date();
//	Date(int d, int m, int y) : date(d), month(m), year(y) {}
//	static Date currentDate;
//	void setValues(int d, int m, int y);
//	void printDate();
//	int getDay() { return date; }
//	int getMonth() { return month; }
//	int getYear() { return year; }
//	bool isMemory(Date rhs);
//	bool isDateWithinTwoDays(Date rhs);
//};
//
//class PostContent
//{
//public:
//	virtual void print()
//	{
//		cout << "Default print called.\n";
//	}
//	virtual ~PostContent();
//};
//
//class PostActivity :public PostContent
//{
//private:
//	int type;
//	char* text;
//public:
//	PostActivity(int i, char* t);
//	void print();
//	~PostActivity();
//};
//
//class Comment
//{
//private:
//	char* ID;
//	char* text;
//	AppNetwork* commentBy;
//	Post* commentedOn;
//	static int totalComments;
//public:
//	Comment(char* cID, Post* cOn, AppNetwork* cBy, char* text);
//	//~Comment();
//	void Print();
//	char* getID() { return ID; }
//	char* getText() { return text; }
//	static void setTotalComments(int c) { totalComments = c; }
//};
//
//class Post
//{
//private:
//	static int noOfPosts;
//	char* postID;
//	Date datePosted;
//	char* text;
//	AppNetwork* sharedBy;
//	AppNetwork** likedBy;
//	int likes;
//	Comment** comments;
//	int totalComments;
//	PostContent** content;
//public:
//	Post();
//	/*virtual */~Post();
//	void ReadDataFromFile(ifstream& fin);
//	void printPost();
//	void setText(char* t) { Helper::strcopy(t, text); }
//	void addComment(Comment* ptr) { comments[totalComments] = ptr; }
//	void setLikedBy(AppNetwork* ptr) { likedBy[likes] = ptr; likes++; }
//	void setSharedBy(AppNetwork* ptr) { sharedBy = ptr; }
//	void setComments(Comment* ptr) { comments[totalComments] = ptr; }
//	void incrementComments() { totalComments++; }
//	void setPostContent(PostActivity* ptr) { content[0] = ptr; }
//	virtual void viewPost();
//	static void setTotalPosts(int P) { noOfPosts = P; }
//	static int getPostTotal() { return noOfPosts; }
//	int getTotalComments() { return totalComments; }
//	char* getID() { return postID; }
//	char* getText() { return text; }
//	Comment** getCommentsList() { return comments; }
//	Date getDate() { return datePosted; }
//	AppNetwork** getLikedBy() { return likedBy; }
//	AppNetwork* getSharedBy() { return sharedBy; }
//	PostContent* getPostContent() { return content[0]; }
//};
//
//class Memory : public Post
//{
//private:
//	Post* oldPostPtr;
//public:
//	Memory(Post* old, char* newText);
//	void viewPost();
//	~Memory();
//};
//
//class AppNetwork
//{
//protected:
//	Post** timeline;
//	int totalTimelinePosts;
//
//public:
//	AppNetwork()
//	{
//		timeline = new Post * [10];
//		for (int i = 0; i < 10; i++)
//		{
//			timeline[i] = nullptr;
//		}
//		totalTimelinePosts = 0;
//	}
//	virtual void addToTimeline(Post* ptr)
//	{
//		timeline[totalTimelinePosts] = ptr;
//		totalTimelinePosts++;
//	}
//	virtual void PrintInfo() { ; }
//	virtual void printUserName() { ; }
//	void viewTimeLine()
//	{
//		for (int i = 0; i < 10; i++)
//		{
//			if (timeline[i])
//			{
//				timeline[i]->viewPost();
//				cout << endl;
//			}
//		}
//	}
//	void PostComment(Post* p, char* t)
//	{
//		char tempID[] = "nPost";
//		Comment* newComment = new Comment(tempID, p, this, t);
//		p->addComment(newComment);
//	}
//	~AppNetwork();
//};
//
//class Page :public AppNetwork
//{
//	char* ID;
//	char* Title;
//	static int totalPages;
//public:
//	Page();
//	void ReadDataFromFile(ifstream& fin);
//	void PrintInfo();
//	~Page();
//	void addToTimeline(Post* ptr);
//	void printUserName() { cout << Title; }
//
//	static void setPageTotal(int P) { totalPages = P; }
//	static int getPageTotal() { return totalPages; }
//	char* getID() { return ID; }
//	char* getTitle() { return Title; }
//	int getTotalTimelinePosts() { return totalTimelinePosts; }
//	Post* getTimeLinePost(int p) { return timeline[p]; }
//
//};
//
//class User :public AppNetwork
//{
//private:
//	char* ID;
//	char* Fname;
//	char* Lname;
//	User** FriendList;
//	Page** LikedPages;
//	int friendsTotal;
//	int pagesTotal;
//	static int totalusers;
//
//public:
//	User();
//	void AddFriend(User*&);
//	void ReadDataFromFile(ifstream& fin);
//	void LikePage(Page*&);
//	void ViewFriendList();
//	void ViewLikedPages();
//	void PrintInfo();
//	void addToTimeline(Post* ptr);
//	void printUserName() { cout << Fname << " " << Lname; }
//	void viewHomePage(Date cDate);
//	void SeeMemories();
//	void shareMemory(Post* p, char* t);
//	~User();
//
//	static void setTotalUser(int U) { totalusers = U; }
//	static int getTotalUsers() { return totalusers; }
//	char* getID() { return ID; }
//	char* getFname() { return Fname; }
//	char* getLname() { return Lname; }
//	User** getFriendList() { return FriendList; }
//};
//
//class Controller
//{
//private:
//	User** AllUsers;
//	Page** AllPages;
//	Post** AllPosts;
//public:
//	User* SearchUserByID(char* id);
//	Page* SearchPageByID(char* id);
//	AppNetwork* SearchNetworkMemberByID(char* id);
//	Post* SearchPostByID(char* id);
//	void LoadAllUser(const char* file);
//	void LoadAllPages(const char* file);
//	void LoadAllPosts(const char* file);
//	void LinkUsersAndPages(const char* file);
//	void LoadAllComments(const char* file);
//	void LoadAllActivities(const char* file);
//	~Controller();
//
//	void LoadData()
//	{
//		LoadAllUser("SocialNetworkUsers.txt");
//		LoadAllPages("SocialNetworkPages.txt");
//		LinkUsersAndPages("UsersFriendsAndLikedPages.txt");
//		LoadAllPosts("SocialNetworkPosts.txt");
//		LoadAllComments("SocialNetworkComments.txt");
//		LoadAllActivities("SocialNetworkActivities.txt");
//	}
//	void Run()
//	{
//		User* currentUser = AllUsers[6];
//		Post* currentPost = AllPosts[4];
//		Page* currentPage = AllPages[0];
//		Date systemDate = Date::currentDate;
//
//		cout << currentUser->getFname() << " " << currentUser->getLname() << " successfully set as the current member.\n";
//
//		cout << "System Date: ";
//		systemDate.printDate();
//		cout << endl << endl;
//
//		currentUser->ViewFriendList();
//		cout << endl;
//		currentUser->ViewLikedPages();
//		cout << endl;
//
//		cout << "Viewing ";
//		currentPost->printPost();
//		currentPost->viewPost();
//
//		cout << "\nList of people who have liked this post: \n";
//		AppNetwork** likedByList = currentPost->getLikedBy();
//		for (int i = 0; i < 10; i++)
//		{
//			if (likedByList[i])
//			{
//				likedByList[i]->PrintInfo();
//			}
//		}
//
//		cout << endl;
//		currentUser->printUserName();
//		cout << " just liked this post! \n";
//		currentPost->setLikedBy(currentUser);
//		cout << "List of people who have liked this post now: \n";
//		for (int i = 0; i < 10; i++)
//		{
//			if (likedByList[i])
//			{
//				likedByList[i]->PrintInfo();
//			}
//		}
//
//		cout << endl << "Viewing timeline of " << currentUser->getFname() << " " << currentUser->getLname() << "\n";
//		currentUser->viewTimeLine();
//
//		cout << endl << "Viewing page of the current brand: \n";
//		currentPage->viewTimeLine();
//
//		cout << "Homepage:\n\n";
//		currentUser->viewHomePage(systemDate);
//
//		cout << "We hope you enjoy looking back and sharing your memories on Facebook, from the most recent to those long ago.\n\n";
//		currentUser->SeeMemories();
//
//		/*char bufferID[10] = "post10";
//		char bufferText[80] = "Never thought i will be specialist in this field.";
//		Post* memoryAddOnPost = SearchPostByID(bufferID);
//		currentUser->shareMemory(memoryAddOnPost, bufferText);
//
//		cout << endl << "Viewing timeline of " << currentUser->getFname() << " " << currentUser->getLname() << "\n";
//		currentUser->viewTimeLine();*/
//
//		char bufferComment[] = "Thanks for the wishes.\n";
//		char bufferID2[] = "post8";
//		Post* postToCommentOn = SearchPostByID(bufferID2);
//		currentUser->PostComment(postToCommentOn, bufferComment);
//		postToCommentOn->incrementComments();
//
//		cout << endl << currentUser->getFname() << " " << currentUser->getLname() << " just added a new comment:\n";
//		postToCommentOn->viewPost();
//	}
//
//};
//
////-------------Initializing Static Variables---------------//
//int User::totalusers = 0;
//int Page::totalPages = 0;
//int Post::noOfPosts = 0;
//int Comment::totalComments = 0;
//Date Date::currentDate = Date(17, 4, 2024);
//
//int main()
//{
//	{
//		Controller mainApp;
//		mainApp.LoadData();
//		mainApp.Run();
//	}
//	cout << "Memory Leaks: " << _CrtDumpMemoryLeaks();
//	return 0;
//}
//
////-------------USER FUNCTIONS--------------//
//User::User()
//{
//	ID = new char[5];
//	Fname = new char[80];
//	Lname = new char[80];
//	FriendList = new User * [10];
//	for (int i = 0; i < 10; i++)
//		FriendList[i] = nullptr;			//EVEN THOUGH NEW WILL NOT BE CREATED FOR THIS PURPOSE(bcs we'll just copy adress), MEMORY MUST BE ALLOCATED FOR 10
//	LikedPages = new Page * [10];
//	for (int i = 0; i < 10; i++)
//		LikedPages[i] = nullptr;
//	pagesTotal = friendsTotal = 0;
//}
//void User::ReadDataFromFile(ifstream& fin)
//{
//	fin >> ID;
//	ID = Helper::shrinkarray(ID);
//	fin >> Fname;
//	Fname = Helper::shrinkarray(Fname);
//	fin >> Lname;
//	Lname = Helper::shrinkarray(Lname);
//
//}
//void User::ViewFriendList()
//{
//	cout << this->getFname() << " " << this->getLname();
//	cout << " - Friend List:\n\n";
//	for (int i = 0; i < 10; i++)
//	{
//		if (FriendList[i])
//		{
//			FriendList[i]->PrintInfo();
//		}
//	}
//}
//void User::ViewLikedPages()
//{
//	cout << this->getFname() << " " << this->getLname();
//	cout << " - Liked Pages:\n\n";
//	for (int i = 0; i < 10; i++)
//	{
//		if (LikedPages[i])
//		{
//			LikedPages[i]->PrintInfo();
//		}
//	}
//}
//void User::PrintInfo()
//{
//	cout << ID << " - " << Fname << " " << Lname << endl;
//}
//void User::AddFriend(User*& newFriend)
//{
//	if (friendsTotal < 10)
//	{
//		FriendList[friendsTotal] = newFriend;
//		friendsTotal++;
//	}
//	else
//		cout << "Error adding a new friend: Maximam Friend limit reached.\n";
//
//}
//void User::LikePage(Page*& likedPage)
//{
//	if (friendsTotal < 10)
//	{
//		LikedPages[pagesTotal] = likedPage;
//		pagesTotal++;
//	}
//	else
//		cout << "Error liking the page: Maximam Page limit reached.\n";
//
//}
//void User::addToTimeline(Post* ptr)
//{
//	timeline[totalTimelinePosts] = ptr;
//	totalTimelinePosts++;
//}
//void User::viewHomePage(Date cDate)
//{
//	for (int i = 0; i < totalTimelinePosts; i++)
//	{
//		if (cDate.isDateWithinTwoDays(timeline[i]->getDate()))
//		{
//			timeline[i]->viewPost();
//			cout << endl;
//		}
//	}
//	for (int i = 0; i < friendsTotal; i++)
//	{
//		for (int j = 0; j < FriendList[i]->totalTimelinePosts; j++)
//		{
//			if (cDate.isDateWithinTwoDays(FriendList[i]->timeline[j]->getDate()))
//			{
//				FriendList[i]->timeline[j]->viewPost();
//				cout << endl;
//			}
//		}
//	}
//
//	for (int i = 0; i < pagesTotal; i++)
//	{
//		for (int j = 0; j < LikedPages[i]->getTotalTimelinePosts(); j++)
//		{
//			if (cDate.isDateWithinTwoDays(LikedPages[i]->getTimeLinePost(j)->getDate()))
//			{
//				LikedPages[i]->getTimeLinePost(j)->viewPost();
//				cout << endl;
//			}
//		}
//	}
//}
//void User::SeeMemories()
//{
//	for (int i = 0; i < totalTimelinePosts; i++)
//	{
//		if (Date::currentDate.isMemory(timeline[i]->getDate()))
//		{
//			cout << Date::currentDate.getYear() - timeline[i]->getDate().getYear() << " Years Ago\n";
//			timeline[i]->viewPost();
//		}
//	}
//}
//void User::shareMemory(Post* p, char* t)
//{
//	timeline[totalTimelinePosts] = new Memory(p, t);
//}
//
//
////-------------PAGE FUNCTIONS--------------//
//Page::Page()
//{
//	ID = new char[5];
//	Title = new char[80];
//}
//void Page::ReadDataFromFile(ifstream& fin)
//{
//	fin >> ID;
//	ID = Helper::shrinkarray(ID);
//	fin.ignore();
//	fin.getline(Title, 79);									//THIS IS HOW TO INPUT A LINE INSTEAD OF WORDS
//	Title = Helper::shrinkarray(Title);
//}
//void Page::PrintInfo()
//{
//	cout << ID << " - " << Title << endl;
//}
//void Page::addToTimeline(Post* ptr)
//{
//	timeline[totalTimelinePosts] = ptr;
//	totalTimelinePosts++;
//}
//
////-------------POST FUNCTIONS--------------//
//Post::Post()
//{
//	postID = new char[10];
//	datePosted = Date();
//	text = new char[100];
//	sharedBy = 0;
//	likedBy = new AppNetwork * [10];
//	for (int i = 0; i < 10; i++)
//		likedBy[i] = nullptr;
//	likes = 0;
//	totalComments = 0;
//	comments = new Comment * [10];
//	for (int i = 0; i < 10; i++)
//	{
//		comments[i] = nullptr;
//	}
//	content = new PostContent * ();
//	content[0] = nullptr;
//}
//void Post::ReadDataFromFile(ifstream& fin)
//{
//	fin >> postID;
//	postID = Helper::shrinkarray(postID);
//	int d, m, y;
//	fin >> d >> m >> y;
//	datePosted.setValues(d, m, y);
//	fin.ignore();
//	fin.getline(text, 99);
//	text = Helper::shrinkarray(text);
//}
//void Post::viewPost()
//{
//	cout << "--- ";
//	sharedBy->printUserName();
//	if (content[0])
//		content[0]->print();
//	cout << " (";
//	datePosted.printDate();
//	cout << ")";
//	cout << endl << "\t\"";
//	cout << text;
//	cout << ".\"";
//	cout << endl;
//	for (int i = 0; i < 10; i++)
//	{
//		if (comments[i])
//		{
//			cout << "\t\t";
//			comments[i]->Print();
//		}
//	}
//}
//void Post::printPost()
//{
//	cout << postID << " shared by ";
//	sharedBy->PrintInfo();
//}
//
////-------------MEMORY FUNCTIONS--------------//
//void Memory::viewPost()
//{
//	cout << "---";
//	oldPostPtr->getSharedBy()->printUserName();
//	cout << " shared a memory---(";
//	Date::currentDate.printDate();
//	cout << ")\n\t";
//
//	cout << getText() << endl;
//
//	int yearsPassed = 0;
//	yearsPassed = (Date::currentDate.getYear()) - (oldPostPtr->getDate().getYear());
//	cout << "\t----" << yearsPassed << " Years Ago----\n";
//	cout << "------------------------------------------------------------------\n";
//	cout << "---";
//	oldPostPtr->getSharedBy()->printUserName();
//	if (oldPostPtr->getPostContent())
//		oldPostPtr->getPostContent()->print();
//	cout << "(";
//	oldPostPtr->getDate().printDate();
//	cout << ")\n\t";
//	cout << oldPostPtr->getText() << endl;
//}
//Memory::Memory(Post* old, char* newText)
//{
//	oldPostPtr = old;
//	setText(newText);
//}
//
////-------------COMMENTS FUNCTIONS--------------//
//Comment::Comment(char* cID, Post* cOn, AppNetwork* cBy, char* textOfComment)
//{
//	ID = new char[10];
//	Helper::strcopy(cID, ID);
//	ID = Helper::shrinkarray(ID);
//	commentedOn = cOn;
//	commentBy = cBy;
//	text = new char[100];
//	Helper::strcopy(textOfComment, text);
//	text = Helper::shrinkarray(text);
//}
//void Comment::Print()
//{
//	commentBy->printUserName();
//	cout << ": " << text << endl;
//}
//
////-------------DATE FUNCTIONS--------------//
//Date::Date()
//{
//	date = 1;
//	month = 1;
//	year = 1960;
//}
//void Date::setValues(int d, int m, int y)
//{
//	date = d;
//	month = m;
//	year = y;
//}
//void Date::printDate()
//{
//	cout << date << "/" << month << "/" << year;
//}
//bool Date::isDateWithinTwoDays(Date rhs)
//{
//	if ((date == rhs.date && month == rhs.month && year == rhs.year) || (date == rhs.date + 1 && month == rhs.month && year == rhs.year))
//		return true;
//	else
//		return false;
//}
//bool Date::isMemory(Date rhs)
//{
//	if (date == rhs.date && month == rhs.month && year != rhs.year)
//	{
//		return true;
//	}
//	else
//		return false;
//}
//
////-------------POST CONTENT FUNCTIONS--------------//
//PostActivity::PostActivity(int i, char* t)
//{
//	text = new char[80];
//	type = i;
//	Helper::strcopy(t, text);
//	text = Helper::shrinkarray(text);
//}
//void PostActivity::print()
//{
//	if (type == 1)
//		cout << " is feeling";
//	else if (type == 2)
//		cout << " is thinking about";
//	else if (type == 3)
//		cout << " is making";
//	else if (type == 4)
//		cout << " is celebrating";
//	cout << text;
//}
//
////-------------CONTROLLER FUNCTIONS--------------//
//void Controller::LoadAllUser(const char* file)
//{
//	ifstream fin(file);
//	if (!fin.is_open())
//	{
//		cout << "Error opening the file Social Network Users.\n";
//	}
//
//	int usersTot = 0;
//	fin >> usersTot;
//	User::setTotalUser(usersTot);
//	AllUsers = new User * [usersTot];
//	for (int i = 0; i < usersTot; i++)
//	{													//??? MEANS NO MEMORY ALLOCATION, XCDCDCDCDC MEANS DEFINED, AOGDVUSDPF MEAND ALLOCATED
//		AllUsers[i] = new User[1];						//THIS SPACE ALLOCATION IS NECESSARY, POINTER DOESNT CALL CONSTRUCTOR, THE ACTUAL NEW USER DOES AND ALLOCATES SPACE
//		AllUsers[i]->ReadDataFromFile(fin);				//ASK:WILL CONSTRUCTOR BE CALLED HERE? DO WE NEED TO ALLOCATE AGAIN?
//	}
//	fin.close();
//
//}
//void Controller::LoadAllPages(const char* file)
//{
//	ifstream fin(file);
//	if (!fin.is_open())
//	{
//		cout << "Error opening the file Social Network Users.\n";
//	}
//
//	int pagesTot = 0;
//	fin >> pagesTot;
//	Page::setPageTotal(pagesTot);
//	AllPages = new Page * [pagesTot];
//	for (int i = 0; i < pagesTot; i++)
//	{
//		AllPages[i] = new Page[1];
//		AllPages[i]->ReadDataFromFile(fin);
//	}
//	fin.close();
//}
//void Controller::LoadAllPosts(const char* file)
//{
//	ifstream fin(file);
//	if (!fin.is_open())
//	{
//		cout << "Error opening the file Social Network Posts.\n";
//		return;
//	}
//
//	int totPosts;
//	fin >> totPosts;
//	Post::setTotalPosts(totPosts);
//
//	AppNetwork* tempNetwork = 0;
//	char tempID[5], end[3] = "-1";
//
//	AllPosts = new Post * [totPosts];
//	for (int i = 0; i < totPosts; i++)
//	{
//		AllPosts[i] = new Post[1];
//		AllPosts[i]->ReadDataFromFile(fin);
//		fin >> tempID;
//		if (tempID[0] == 'u')
//			tempNetwork = SearchUserByID(tempID);
//		else if (tempID[0] == 'p')
//			tempNetwork = SearchPageByID(tempID);
//		AllPosts[i]->setSharedBy(tempNetwork);
//		tempNetwork->addToTimeline(AllPosts[i]);
//		fin >> tempID;
//		while (!Helper::compareText(end, tempID))
//		{
//			if (tempID[0] == 'u')
//				tempNetwork = SearchUserByID(tempID);
//			else if (tempID[0] == 'p')
//				tempNetwork = SearchPageByID(tempID);
//			AllPosts[i]->setLikedBy(tempNetwork);
//			//Add to timeline here the post as well
//			fin >> tempID;
//		}
//		fin.ignore();
//	}
//	fin.close();
//}
//void Controller::LoadAllComments(const char* file)
//{
//	ifstream fin(file);
//	if (!fin.is_open())
//	{
//		cout << "Error opening the file Social Network Comments.\n";
//		return;
//	}
//
//	int totComments;
//	fin >> totComments;
//	Comment::setTotalComments(totComments);
//
//	char cID[10], text[80], bufferID[10];
//	Post* commentOn;
//	AppNetwork* commentBy;
//
//	for (int i = 0; i < totComments; i++)
//	{
//		fin >> cID;
//		fin >> bufferID;
//		commentOn = SearchPostByID(bufferID);
//		fin >> bufferID;
//		commentBy = SearchNetworkMemberByID(bufferID);
//		fin.ignore();
//		fin.getline(text, 79);
//		Comment* comment = new Comment(cID, commentOn, commentBy, text);
//		commentOn->setComments(comment);
//		commentOn->incrementComments();
//	}
//}
//void Controller::LinkUsersAndPages(const char* file)
//{
//	ifstream fin(file);
//	if (!fin.is_open())
//	{
//		cout << "Error opening the file linking pages and users.\n";
//		return;
//	}
//
//	char buffer[5], end[3];
//	end[0] = '-';
//	end[1] = '1';
//	end[2] = '\0';
//	User* currentUser;
//	User* addedUser;
//	Page* likedPage;
//	fin >> buffer;
//	while (!Helper::compareText(buffer, end))
//	{
//		currentUser = SearchUserByID(buffer);
//		fin >> buffer;
//		while (!Helper::compareText(buffer, end))
//		{
//			addedUser = SearchUserByID(buffer);
//			currentUser->AddFriend(addedUser);
//			fin >> buffer;
//		}
//		fin >> buffer;
//		while (!Helper::compareText(buffer, end))
//		{
//			likedPage = SearchPageByID(buffer);
//			currentUser->LikePage(likedPage);
//			fin >> buffer;
//		}
//		fin >> buffer;
//	}
//
//}
//void Controller::LoadAllActivities(const char* file)
//{
//	int totalActivities, bufferType;
//	char bufferid[10], bufferText[80];
//	Post* activityOn;
//
//	ifstream fin(file);
//	if (!fin.is_open())
//	{
//		cout << "Error opening the file Social Network Activities.\n";
//		return;
//	}
//
//	fin >> totalActivities;
//	for (int i = 0; i < totalActivities; i++)
//	{
//		fin >> bufferid;
//		activityOn = SearchPostByID(bufferid);
//		fin >> bufferType;
//		fin.getline(bufferText, 79);
//		PostActivity* activityBuffer = new PostActivity(bufferType, bufferText);
//		activityOn->setPostContent(activityBuffer);
//	}
//
//}
//AppNetwork* Controller::SearchNetworkMemberByID(char* id)
//{
//	switch (id[0]) {
//
//	case'u':
//	case'U':
//		return SearchUserByID(id);
//	case 'p':
//	case 'P':
//		return SearchPageByID(id);
//	default:
//		return nullptr;
//	}
//
//}
//User* Controller::SearchUserByID(char* id)
//{
//	int usersTot = User::getTotalUsers();
//	for (int i = 0; i < usersTot; i++)
//	{
//		if (Helper::compareText(AllUsers[i]->getID(), id))
//		{
//			//cout << "User found: ";
//			//AllUsers[i]->PrintUser();
//			return AllUsers[i];
//		}
//	}
//}
//Page* Controller::SearchPageByID(char* id)
//{
//	int pagesTot = Page::getPageTotal();
//	for (int i = 0; i < pagesTot; i++)
//	{
//		if (Helper::compareText(AllPages[i]->getID(), id))
//		{
//			return AllPages[i];
//		}
//	}
//}
//Post* Controller::SearchPostByID(char* id)
//{
//	int postsTot = Post::getPostTotal();
//	for (int i = 0; i < postsTot; i++)
//	{
//		if (Helper::compareText(AllPosts[i]->getID(), id))
//		{
//			return AllPosts[i];
//		}
//	}
//}
//
////-------------DESTRUCTORS FUNCTIONS--------------//
//
//User::~User()
//{
//	//cout << "User Destructor class called for ";
//	//this->printUserName();
//	if (ID)
//		delete[] ID;
//	if (Fname)
//		delete[] Fname;
//	if (Lname)
//		delete[] Lname;
//	if (FriendList)
//		delete[]  FriendList;
//	if (LikedPages)
//		delete[] LikedPages;
//}
//AppNetwork::~AppNetwork()
//{
//	//cout << "AppNetwork Destructor: Timeline deleted for ";
//	//this->printUserName();
//	//cout << endl;
//	for (int i = 0; i < totalTimelinePosts; i++)
//		if (timeline[i])
//			delete[] timeline[i];
//	if (timeline)
//		delete[] timeline;
//}
//Post::~Post()
//{
//	/*cout << "Post Destructor: ";
//	this->printPost();
//	cout << endl;*/
//	if (postID)
//		delete[] postID;
//	if (text)
//		delete[] text;
//	if (likedBy)
//		delete[] likedBy;
//	for (int i = 0; i < totalComments; i++)
//	{
//		delete[] comments[i]->getID();
//		delete[] comments[i]->getText();
//		delete[] comments[i];
//	}
//	delete[] comments;
//	if (content[0])
//		delete[] content[0];
//	delete[] content;
//}
//Page::~Page()
//{
//	/*cout << "Post Destructor: Timeline deleted for ";
//	this->printUserName();*/
//	//cout << endl;
//	if (ID)
//		delete[] ID;
//	if (Title)
//		delete[] Title;
//}
//
//PostActivity::~PostActivity()
//{
//	//cout << "PostActivity Destructor: ";
//	//cout << endl;
//	if (text)
//		delete[] text;
//}
//PostContent::~PostContent()
//{
//	//cout << "PostContent Destructor: ";
//}
//Controller::~Controller()
//{
//	//cout << "Controller Destructor called\n";
//	for (int i = 0; i < 20; ++i)
//	{
//		if (AllUsers[i])
//			delete[] AllUsers[i];
//	}
//	delete[] AllUsers;
//
//	// Delete AllPages if it's allocated
//	if (AllPages)
//	{
//		for (int i = 0; i < 12; ++i)
//			if (AllPages[i])
//				delete[] AllPages[i];
//		delete[] AllPages;
//	}
//	if (AllPosts)
//	{/*
//		for (int i = 0; i < 12; ++i)
//			if (AllPosts[i])
//				delete[] AllPosts[i];*/
//		delete[] AllPosts;
//	}
//}
//Memory::~Memory()
//{
//	//cout << "Memory Destructor called\n";
//	Post::~Post();
//	delete[] this;
//}
//
//Date::~Date()
//{
//	//cout << "Date Destructor called\n";
//}
//
////Why is comment destructor giving me error???