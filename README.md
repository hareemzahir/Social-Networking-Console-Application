# Social Networking Console Application
 Object Oriented Programming Final project, semester 2 year 1
### Project Description

This project is a console-based social network application in C++ with the following functionalities:
- Users with unique IDs and names can have up to 10 friends and liked pages.
- Pages with unique IDs can share posts, each with comments, likes, and activities.
- Activities include "feeling," "thinking about," "making," and "celebrating."

### Required Functionalities

#### Phase I:
- Set current user by ID.
- View a user’s friend list.
- View a user’s liked pages.

#### Phase II:
- View user’s timeline (their posts and comments).
- View a page's posts by page ID.
- View a post with comments by post ID.
- Like a post and view the list of people who liked it.

#### Phase III:
- Comment on a post.
- View the home page showing recent posts from friends and liked pages.
- Add a post with an activity.
- Share a memory.

### Instructions

- All interactions are hardcoded in the `Controller::Run()` function.
- No global variables or functions allowed.
- Use dynamic memory allocation with proper deallocation.
- Double pointers should be null if there are no friends, liked pages, or posts.
