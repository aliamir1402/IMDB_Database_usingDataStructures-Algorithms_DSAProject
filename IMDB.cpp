#include<iostream>
#include<fstream>
#include<string>
#include <iostream>
using namespace std;
#define size 50 //pre-defined size of list e.g. 500, 1000 or 5000

class Movie;
class Movienode;
class MovieList;
class Actor;
class Actornode;
class ActorList;
class Director;
class Directornode;
class DirectorList;


struct Array
{
	string index
		, tmovie
		, genres
		, title_year
		, imdb_score
		, num_critic_for_reviews
		, duration
		, gross
		, num_voted_users
		, cast_total_facebook_likes
		, facenumber_in_poster
		, plot_keywords
		, movie_imdb_link
		, num_user_for_reviews
		, language
		, country
		, content_rating
		, budget
		, aspect_ratio
		, movie_facebook_likes
		, color
		, actor1_name
		, actor1_facebook_likes
		, actor2_name
		, actor2_facebook_likes
		, actor3_name
		, actor3_facebook_likes
		, director_name
		, director_facebook_likes;
};
//Actor Tree
class Actor
{
public:
	string actor_name
		, actor_facebook_likes;
};
class Actornode
{
public:
	Actor data;
	Actornode* left;
	Actornode* right;
};
//stores the node address of the actor searched in the tree to place in movie tree
Actornode* temp_actor_node = new Actornode;
class ActorList
{
public:
	Actornode* aroot;
	int alength = 0;
	int f = 0;
	Actornode* l = new Actornode;
	Actornode* r = new Actornode;
	bool aisEmpty()
	{
		return alength == 0;
	}
	void aInsertToTree(string str, string num_likes)
	{
		Actornode* newnode = new Actornode;
		Actornode* temp = new Actornode;
		Actornode* n = new Actornode;
		int flag = 0;
		f = 0;
		aSearchDublicate(aroot, str);
		if (f != 1)
		{
			newnode->data.actor_name = str;
			newnode->data.actor_facebook_likes = num_likes;
			newnode->left = l;
			newnode->right = r;
			if (!aisEmpty())
				temp = aroot;
			flag = 0;

			if (aisEmpty()) //the list is empty, then root node
			{
				aroot = newnode;
			}
			else  //if the tree contains the value
			{
				while (flag == 0) //value is not inserted, then flag is false 
				{
					if (str < temp->data.actor_name) //if the value is less than current node
					{
						if (temp->left == l)
						{
							temp->left = newnode; //adding the node
							flag = 1; //once inserted flag becomes true
						}
						else
							temp = temp->left; //if left leaf is null, then temp value updated
					}
					else
					{
						if (temp->right == r) //if the value is more than current node
						{
							temp->right = newnode;//adding the node
							flag = 1;//once inserted flag becomes true
						}
						else
							temp = temp->right;//if right leaf is null, then temp value updated
					}
				}
			}
			alength++;//the length of tree incremented
		}
		else
		{
			return;
		}
	}
	void aSearchDublicate(Actornode* node, string ActorName)
	{
		if (!aisEmpty())
		{
			if (node->data.actor_name == ActorName)
			{
				f = 1;
				return;
			}
			else
			{
				if (!(node == l || node == r))
				{
					aSearchDublicate(node->left, ActorName);
					aSearchDublicate(node->right, ActorName);
				}
			}
		}
	}
	void aSearch(Actornode* node, string ActorName)
	{
		if (!aisEmpty())
		{
			//cout << "AliAmirKhawaja" << endl;
			if (node->data.actor_name == ActorName)
			{
				temp_actor_node = node;
				return;
			}
			else
			{
				if (!(node == l || node == r))
				{
					aSearch(node->left, ActorName);
					aSearch(node->right, ActorName);
				}
			}
		}
	}
	void aPreOrder(Actornode* node)
	{
		if (!(node == l || node == r))
		{
			cout << node->data.actor_name << endl; //outputing first root node
			aPreOrder(node->left);//the left nodes 
			aPreOrder(node->right);//and then right node of each node
		}
	}
};

//Director Tree
class Director
{
public:
	string director_name
		, director_facebook_likes;
};
class Directornode
{
public:
	Director data;
	Directornode* left;
	Directornode* right;
};
//stores the node address of the actor searched in the tree to place in movie tree
Directornode* temp_director_node = new Directornode;
class DirectorList
{
public:
	Directornode* droot;
	int dlength = -1;
	int f = 0;
	Directornode* l = new Directornode;
	Directornode* r = new Directornode;

	bool disEmpty()
	{
		return dlength == -1;
	}
	void dInsertToTree(string str, string num_likes)
	{
		Directornode* newnode = new Directornode;
		Directornode* temp = new Directornode;
		Directornode* n = new Directornode;
		int flag = 0;
		f = 0;
		dSearchDublicate(droot, str);
		if (f != 1)
		{
			newnode->data.director_name = str;
			newnode->data.director_facebook_likes = num_likes;
			newnode->left = l;
			newnode->right = r;
			if (!disEmpty())
				temp = droot;
			flag = 0;

			if (disEmpty()) //the list is empty, then root node
			{
				droot = newnode;
			}
			else  //if the tree contains the value
			{
				while (flag == 0) //value is not inserted, then flag is false 
				{
					if (str < temp->data.director_name) //if the value is less than current node
					{
						if (temp->left == l)
						{
							temp->left = newnode; //adding the node
							flag = 1; //once inserted flag becomes true
						}
						else
							temp = temp->left; //if left leaf is null, then temp value updated
					}
					else
					{
						if (temp->right == r) //if the value is more than current node
						{
							temp->right = newnode;//adding the node
							flag = 1;//once inserted flag becomes true
						}
						else
							temp = temp->right;//if right leaf is null, then temp value updated
					}
				}
			}
			dlength++;//the length of tree incremented
		}
		else
		{
			return;
		}
	}
	void dSearchDublicate(Directornode* node, string DirectorName)
	{
		if (!disEmpty())
		{
			if (node->data.director_name == DirectorName)
			{
				f = 1;
				return;
			}
			else
			{
				if (!(node == l || node == r))
				{
					dSearchDublicate(node->left, DirectorName);
					dSearchDublicate(node->right, DirectorName);
				}
			}
		}
	}
	void dSearch(Directornode* node, string DirectorName)
	{
		if (!disEmpty())
		{
			if (node->data.director_name == DirectorName)
			{
				temp_director_node = node;
				return;
			}
			else
			{
				if (!(node == l || node == r))
				{
					dSearch(node->left, DirectorName);
					dSearch(node->right, DirectorName);
				}
			}
		}
	}
	void dPreOrder(Directornode* node)
	{
		if (!(node == l || node == r))
		{
			cout << node->data.director_name << endl; //outputing first root node
			dPreOrder(node->left);//the left nodes 
			dPreOrder(node->right);//and then right node of each node
		}
	}
};
int count_Movie = 0;
struct G
{
	int length;
	string index
		, tmovie
		, title_year
		, imdb_score
		, num_critic_for_reviews
		, duration
		, gross
		, num_voted_users
		, cast_total_facebook_likes
		, facenumber_in_poster
		, plot_keywords
		, movie_imdb_link
		, num_user_for_reviews
		, language
		, country
		, content_rating
		, budget
		, aspect_ratio
		, movie_facebook_likes
		, color
		, actor1_name
		, actor1_facebook_likes
		, actor2_name
		, actor2_facebook_likes
		, actor3_name
		, actor3_facebook_likes
		, director_name
		, director_facebook_likes;
	string* Gen = new string[10];
};

//Movie Tree
class Movie
{
public:
	string index
		, mtitle
		, title_year
		, imdb_score
		, num_critic_for_reviews
		, duration
		,genres
		, gross
		, num_voted_users
		, cast_total_facebook_likes
		, facenumber_in_poster
		, plot_keywords
		, movie_imdb_link
		, num_user_for_reviews
		, language
		, country
		, content_rating
		, budget
		, aspect_ratio
		, movie_facebook_likes
		, color;
	Actornode* actor_1_name_
		, * actor_1_facebook_likes_
		, * actor_2_name_
		, * actor_2_facebook_likes_
		, * actor_3_name_
		, * actor_3_facebook_likes_;
	Directornode* director_name_
		, * director_facebook_likes_;
};
int HashAlgo(int index)
{
	return (index % 7);
}
struct Hash
{
	Movie data;
	Movienode* next;
};
Hash* HTable = new Hash[8];
class Movienode
{
public:
	Movie data;
	Movienode* left;
	Movienode* right;
};
Movienode* F12 = new Movienode[size];
Movienode* F02 = new Movienode[size];
Movienode* F03 = new Movienode[size];

G* F11 = new G[size];
int count_CoActor = 0;
int count_CoActor1 = 0;
int count_CoActor2 = 0;
int count_CoActor3 = 0;
int counter = 0;
int count__ = 0;
class MovieList
{
protected:
	Movienode* ploc;
	Movienode* loc;
	int count = -1;
	Movienode* l = new Movienode;
	Movienode* r = new Movienode;
	Movienode* nullnode = new Movienode;

public:
	int length = 0;
	Movienode* n = new Movienode;
	Movienode* root;
	int c = 0;
	bool isEmpty()//checks whether the tree is empty
	{
		return length == 0;
	}
	void InsertToTree(Array list, ActorList* obj, DirectorList* obj_)
	{
		Movienode* newnode = new Movienode;
		int flag = 0;
		Movienode* temp = new Movienode;
		{
			newnode->data.index = list.index;
			newnode->data.mtitle = list.tmovie;
			newnode->data.genres = list.genres;
			newnode->data.title_year = list.title_year;
			newnode->data.imdb_score = list.imdb_score;
			newnode->data.num_critic_for_reviews = list.num_critic_for_reviews;
			newnode->data.duration = list.duration;
			newnode->data.gross = list.gross;
			newnode->data.num_voted_users = list.num_voted_users;
			newnode->data.cast_total_facebook_likes = list.cast_total_facebook_likes;
			newnode->data.facenumber_in_poster = list.facenumber_in_poster;
			newnode->data.plot_keywords = list.plot_keywords;
			newnode->data.movie_imdb_link = list.movie_imdb_link;
			newnode->data.num_user_for_reviews = list.num_user_for_reviews;
			newnode->data.language = list.language;
			newnode->data.country = list.country;
			newnode->data.content_rating = list.content_rating;
			newnode->data.budget = list.budget;
			newnode->data.aspect_ratio = list.aspect_ratio;
			newnode->data.movie_facebook_likes = list.movie_facebook_likes;
			newnode->data.color = list.color;

			obj->aSearch(obj->aroot, list.actor1_name);
			newnode->data.actor_1_name_ = temp_actor_node;
			newnode->data.actor_1_facebook_likes_ = temp_actor_node;
			obj->aSearch(obj->aroot, list.actor2_name);
			newnode->data.actor_2_name_ = temp_actor_node;
			newnode->data.actor_2_facebook_likes_ = temp_actor_node;
			obj->aSearch(obj->aroot, list.actor3_name);
			newnode->data.actor_3_name_ = temp_actor_node;
			newnode->data.actor_3_facebook_likes_ = temp_actor_node;
			obj_->dSearch(obj_->droot, list.director_name);
			newnode->data.director_name_ = temp_director_node;
			newnode->data.director_facebook_likes_ = temp_director_node;
		}
		newnode->left = l;
		newnode->right = r;
		if (!isEmpty())
			temp = root;
		flag = 0;

		if (isEmpty()) //the list is empty, then root node
		{
			root = newnode;
		}
		else  //if the tree contains the value
		{
			while (flag == 0) //value is not inserted, then flag is false 
			{
				if (list.index < temp->data.index) //if the value is less than current node
				{
					if (temp->left == l)
					{
						temp->left = newnode; //adding the node
						flag = 1; //once inserted flag becomes true
					}
					else
						temp = temp->left; //if left leaf is null, then temp value updated
				}
				else
				{
					if (temp->right == r) //if the value is more than current node
					{
						temp->right = newnode;//adding the node
						flag = 1;//once inserted flag becomes true
					}
					else
						temp = temp->right;//if right leaf is null, then temp value updated
				}
			}
		}
		length++;//the length of tree incremented
	}
	//Function 1
	void SearchActor(int index, string aname)
	{
		Movienode* node = new Movienode;
		Movienode* n = new Movienode;
		int x = 0;
		if ((HTable[index].data.actor_1_name_->data.actor_name == aname ||
			HTable[index].data.actor_2_name_->data.actor_name == aname || HTable[index].data.actor_3_name_->data.actor_name == aname)
			&& x == 0 && HTable[index].data.index != "NA") 
		{
			{
				string x = HTable[index].data.index;
				n->data.index = x;
				node->data.index = n->data.index;

				x = HTable[index].data.mtitle;
				n->data.mtitle = x;
				node->data.mtitle = n->data.mtitle;

				x = HTable[index].data.genres;
				n->data.genres = x;
				node->data.genres = n->data.genres;

				x = HTable[index].data.title_year;
				n->data.title_year = x;
				node->data.title_year = n->data.title_year;
			}
			F02[count_Movie] = *node;
			count_Movie++;
			x = 1;
		}
		if (x == 1)
		{
			TreverseActor(HTable[index].next, aname);
		}
	}
	void TreverseActor(Movienode* node, string aname)
	{
		if (!(node == l || node == r))
		{
			if (node->data.actor_1_name_->data.actor_name == aname || node->data.actor_2_name_->data.actor_name == aname
				|| node->data.actor_3_name_->data.actor_name == aname)
				F02[count_Movie++] = *node;
			TreverseActor(node->left, aname);
			TreverseActor(node->right, aname);
		}
	}
	//Function 2	
	void SearchCoActor(int index, string aname)
	{
		TreverseCoActor(HTable[index].next, aname);
	}
	void TreverseCoActor(Movienode* node, string aname)
	{
		if (!(node == l || node == r))
		{
			if (node->data.actor_1_name_->data.actor_name == aname || node->data.actor_2_name_->data.actor_name == aname
				|| node->data.actor_3_name_->data.actor_name == aname)
				F03[count_CoActor++] = *node;
			TreverseCoActor(node->left, aname);
			TreverseCoActor(node->right, aname);
		}
	}
	//Function 5
	void SearchMovieWithDirector(int index, string directorname)
	{
		SearchTreeD(HTable[index].next, directorname);
	}
	void SearchTreeD(Movienode* node, string directorname)
	{
		if (!(node == l || node == r))
		{
			if (node->data.director_name_->data.director_name == directorname)
				cout << " Movie: " << node->data.mtitle << endl;
			SearchTreeD(node->left, directorname);
			SearchTreeD(node->right, directorname);
		}
	}
	//Function 7
	void SearchByTitle(int index, string title)
	{
		SearchTreeT(HTable[index].next, title);
	}
	void SearchTreeT(Movienode* node, string title)
	{
		if (!(node == l || node == r))
		{
			if (node->data.mtitle == title)
				cout << " Tilte: " << node->data.mtitle << " \n Release Year: " << node->data.title_year
				<< " \n Rating: " << node->data.imdb_score << " \n Duration: " << node->data.duration <<
				" \n Actor 1: " << node->data.actor_1_name_->data.actor_name << " \n Actor 2: " << node->data.actor_2_name_->data.actor_name << " \n Actor 3: "
				<< node->data.actor_3_name_->data.actor_name << " \n Director: " << node->data.director_name_->data.director_name << endl << endl;
			//outputing details of the movie node 				
			SearchTreeT(node->left, title);
			SearchTreeT(node->right, title);
		}
	}		
	//Function 8
	void SearchByYear(int index, string year)
	{
		if (HTable[index].data.title_year == year)
			cout << " Year: " << HTable[index].data.title_year << " Title: " << HTable[index].data.mtitle << endl;
		SearchTreeY(HTable[index].next, year);
	}
	void SearchTreeY(Movienode* node, string year)
	{
		if (!(node == l || node == r))
		{
			if (node->data.title_year == year)
				PrintYearMovies(node);
			SearchTreeY(node->left, year);
			SearchTreeY(node->right, year);
		}
	}
	void PrintYearMovies(Movienode* node)
	{
		cout << " Year: " << node->data.title_year << " Title: " << node->data.mtitle << endl;
	}
	//Function 9
	void PrintYearWise(int index)
	{
		{
			int x = 0;
			Movienode* node = new Movienode;
			Movienode* n = new Movienode;
			if (HTable[index].data.index != "NA" && x == 0)
			{
				{
					string x = HTable[index].data.index;
					n->data.index = x;
					node->data.index = n->data.index;

					x = HTable[index].data.mtitle;
					n->data.mtitle = x;
					node->data.mtitle = n->data.mtitle;

					x = HTable[index].data.genres;
					n->data.genres = x;
					node->data.genres = n->data.genres;

					x = HTable[index].data.title_year;
					n->data.title_year = x;
					node->data.title_year = n->data.title_year;
				}
				F12[counter] = *node;
				counter++;
				x = 1;
			}
			if (x == 1)
			{
				TreverseRatingWise(HTable[index].next);
			}
		}
	}
	//Function 11
	void PrintMovieRatingWise(int index)
	{
		int x = 0;
		Movienode* node = new Movienode;
		Movienode* n = new Movienode;
		if (HTable[index].data.index != "NA" && x == 0)
		{
			{
				string x = HTable[index].data.index;
				n->data.index = x;
				node->data.index = n->data.index;

				x = HTable[index].data.mtitle;
				n->data.mtitle = x;
				node->data.mtitle = n->data.mtitle;

				x = HTable[index].data.genres;
				n->data.genres = x;
				node->data.genres = n->data.genres;

				x = HTable[index].data.title_year;
				n->data.title_year = x;
				node->data.title_year = n->data.title_year;
			}
			F12[counter] = *node;
			counter++;
			x = 1;
		}
		if (x == 1)
		{
			TreverseRatingWise(HTable[index].next);
		}
	}
	void TreverseRatingWise(Movienode* node)
	{
		if (!(node == l || node == r))
		{
			F12[counter++] = *node;
			TreverseRatingWise(node->left);
			TreverseRatingWise(node->right);
		}
	}
	//FUNCTIONS TO INSERT THE DATA
	void PreOrder(Movienode* node)
	{
		if (!(node == l || node == r))
		{
			cout << " -> ";
			cout << node->data.mtitle << "  "; //outputing first root node
			PreOrder(node->left);//the left nodes and then right node of each node
			PreOrder(node->right);
		}
	}
	void InsertIntoTable(Array list, int index, ActorList* obj, DirectorList* obj_)
	{
		if (HTable[index].data.index == "NA")
		{
			HTable[index].data.index = list.index;
			HTable[index].data.mtitle = list.tmovie;
			HTable[index].data.genres = list.genres;
			HTable[index].data.title_year = list.title_year;
			HTable[index].data.imdb_score = list.imdb_score;
			HTable[index].data.num_critic_for_reviews = list.num_critic_for_reviews;
			HTable[index].data.duration = list.duration;
			HTable[index].data.gross = list.gross;
			HTable[index].data.num_voted_users = list.num_voted_users;
			HTable[index].data.cast_total_facebook_likes = list.cast_total_facebook_likes;
			HTable[index].data.facenumber_in_poster = list.facenumber_in_poster;
			HTable[index].data.plot_keywords = list.plot_keywords;
			HTable[index].data.movie_imdb_link = list.movie_imdb_link;
			HTable[index].data.num_user_for_reviews = list.num_user_for_reviews;
			HTable[index].data.language = list.language;
			HTable[index].data.country = list.country;
			HTable[index].data.content_rating = list.content_rating;
			HTable[index].data.budget = list.budget;
			HTable[index].data.aspect_ratio = list.aspect_ratio;
			HTable[index].data.movie_facebook_likes = list.movie_facebook_likes;
			HTable[index].data.color = list.color;

			obj->aSearch(obj->aroot, list.actor1_name);
			HTable[index].data.actor_1_name_ = temp_actor_node;
			HTable[index].data.actor_1_facebook_likes_ = temp_actor_node;

			obj->aSearch(obj->aroot, list.actor2_name);
			HTable[index].data.actor_2_name_ = temp_actor_node;
			HTable[index].data.actor_2_facebook_likes_ = temp_actor_node;

			obj->aSearch(obj->aroot, list.actor3_name);
			HTable[index].data.actor_3_name_ = temp_actor_node;
			HTable[index].data.actor_3_facebook_likes_ = temp_actor_node;

			obj_->dSearch(obj_->droot, list.director_name);
			HTable[index].data.director_name_ = temp_director_node;
			HTable[index].data.director_facebook_likes_ = temp_director_node;

			HTable[index].next = n;
		}
		else
		{
			InsertToTree(list, obj, obj_);
			if (length == 1)
				HTable[index].next = root;
		}
	}
	void PrintHash(int i)
	{
		if (HTable[i].data.index != "NA")
		{
			cout << i << ". " << HTable[i].data.mtitle << " ";
			if (HTable[i].next != n)
				PreOrder(HTable[i].next);
			cout << endl; cout << endl;
		}
	}
};

int binarySearch(string arr[], int l, int r, string item);

//Function 4
void SearchTwoActorsInMovie(Array arry[], string str1, string str2)
{
	int index1 = -1;
	int index2 = -1;
	int flag = 0;

	for (int i = 0; i < size; i++)
	{
		//In the array the index at which the for both strings the index is same output data
		if (((arry[i].actor1_name == str1 || arry[i].actor2_name == str1 || arry[i].actor3_name == str1))
			&& (arry[i].actor1_name == str2 || arry[i].actor2_name == str2 || arry[i].actor3_name == str2))
		{
			cout << " Actors:\n " << str1 << "\n " << str2 << endl;
			cout << " have acted together in this Movie : " << arry[i].tmovie << endl;
			cout << endl;
			flag = 1;
		}
	}
	if (flag == 0)
		cout << " They have never acted together." << endl;
}
//Function 6
void PrintDirectorsGenre(string gen, G arry[])
{
	int index;
	for (int i = 0; i < size; i++)
	{
		index = binarySearch(arry[i].Gen, 0, arry[i].length, gen);
		if (index != -1)
		{
			cout << " Director Name: " << arry[i].director_name << endl;
		}
	}
}
//Function 10
void PrintMoviesGernes(G arry[], string gen)
{
	int index;
	for (int i = 0; i < size; i++)
	{
		index = binarySearch(arry[i].Gen, 0, arry[i].length, gen);
		if (index != -1)
		{
			F11[count__] = arry[i]; count__++;
		}
	}
}

//Utility Functions Sorting and Searches
int binarySearch(string arr[], int l, int r, string item)
{
	if (r >= l) {
		int mid = l + (r - l) / 2;

		// If the element is present at the middle
		// itself
		
			if (arr[mid] == item)
				return mid;

		// If element is smaller than mid, then
		// it can only be present in left subarray
		if (arr[mid] > item)
			return binarySearch(arr, l, mid - 1, item);

		// Else the element can only be present
		// in right subarray
		return binarySearch(arr, mid + 1, r, item);
	}

	// We reach here when element is not
	// present in array
	return -1;
}
void swap(Movienode* a, Movienode* b)
{
	Movienode t = *a;
	*a = *b;
	*b = t;
}
int partition(Movienode arr[], int low, int high)
{
	Movienode a, b, c, d;
	string pivot = (arr[high].data.imdb_score); // pivot 
	int i = (low - 1); // Index of smaller element and indicates the right position of pivot found so far

	for (int j = low; j <= high - 1; j++)
	{
		// If current element is smaller than the pivot 
		if ((arr[j].data.imdb_score) < pivot)
		{
			i++; // increment index of smaller element 
			a = arr[i];
			b = arr[j];
			swap(&a, &b);
			arr[i] = a;
			arr[j] = b;
		}
	}
	c = arr[i + 1];
	d = arr[high];
	swap(&c, &d);
	arr[i + 1] = c;
	arr[high] = d;
	return (i + 1);
}
void quickSort(Movienode arr[], int low, int high)
{
	if (low < high)
	{
		/* pi is partitioning index, arr[p] is now
		at right place */
		int pi = partition(arr, low, high);

		// Separately sort elements before 
		// partition and after partition 
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}
int partition_(Movienode arr[], int low, int high, int option)
{
	Movienode a, b, c, d;
	string pivot = (arr[high].data.title_year); // pivot 
	int i = (low - 1); // Index of smaller element and indicates the right position of pivot found so far

	for (int j = low; j <= high - 1; j++)
	{
		// If current element is smaller than the pivot 
		if (option == 0)
		{
			if ((arr[j].data.title_year) < pivot)
			{
				i++; // increment index of smaller element 
				a = arr[i];
				b = arr[j];
				swap(&a, &b);
				arr[i] = a;
				arr[j] = b;
			}
		}
		else
		{
			if ((arr[j].data.title_year) > pivot)
			{
				i++; // increment index of smaller element 
				a = arr[i];
				b = arr[j];
				swap(&a, &b);
				arr[i] = a;
				arr[j] = b;
			}
		}
	}
	c = arr[i + 1];
	d = arr[high];
	swap(&c, &d);
	arr[i + 1] = c;
	arr[high] = d;
	return (i + 1);
}
void quickSort_(Movienode arr[], int low, int high, int option)
{
	if (low < high)
	{
		/* pi is partitioning index, arr[p] is now
		at right place */
		int pi = partition_(arr, low, high, option);

		// Separately sort elements before 
		// partition and after partition 
		quickSort_(arr, low, pi - 1, option);
		quickSort_(arr, pi + 1, high, option);
	}
}
void swap__(G* a, G* b)
{
	G t = *a;
	*a = *b;
	*b = t;
}
int partition__(G arr[], int low, int high)
{
	G a, b, c, d;
	string pivot = arr[high].imdb_score; // pivot 
	int i = (low - 1); // Index of smaller element and indicates the right position of pivot found so far

	for (int j = low; j <= high - 1; j++)
	{
		// If current element is smaller than the pivot 
		if ((arr[j].imdb_score) > pivot)
		{
			i++; // increment index of smaller element 
			a = arr[i];
			b = arr[j];
			swap__(&a, &b);
			arr[i] = a;
			arr[j] = b;
		}
	}
	c = arr[i + 1];
	d = arr[high];
	swap__(&c, &d);
	arr[i + 1] = c;
	arr[high] = d;
	return (i + 1);
}
void quickSort__(G arr[], int low, int high)
{
	if (low < high)
	{
		/* pi is partitioning index, arr[p] is now
		at right place */
		int pi = partition__(arr, low, high);

		// Separately sort elements before 
		// partition and after partition 
		quickSort__(arr, low, pi - 1);
		quickSort__(arr, pi + 1, high);
	}
}

void menu()
{
	cout << "--------------------------IMBD-----------------------------" << endl;
	cout << "Press 1 to  Search profile of an actor  " << endl;
	cout << "Press 2 to  Search co-actors of an actor  " << endl;
	cout << "Press 3 to Print All the Movies Data " << endl;
	cout << "Press 4 to Checks whether A and B are co-actors or not? " << endl;
	cout << "Press 5 to Search director " << endl;
	cout << "Press 6 to Print directors who have directed movies of a certain genre  " << endl;
	cout << "Press 7  to Search a movie " << endl;
	cout << "Press 8 to Search movies released in a given year " << endl;
	cout << "Press 9 to Print movies year wise  " << endl;
	cout << "Press 10 Search movies based on genre " << endl;
	cout << "Press 11 Print movies rating-wise  " << endl;
	cout << " Enter Option For the Function to run: " << endl;
}
	
int main()
{
	int option = 0;
	ifstream myfile;
	MovieList* obj_Movie = new MovieList[8];
	ActorList* obj_Actor = new ActorList;
	DirectorList* obj_Director = new DirectorList;
	Array* arry = new Array[size];
	G* arr = new G[size];
	char* line = new char[10000];
	char* Genress = new char[10000];
	for (int x = 1; x < 8; x++)
	{
		HTable[x].data.index = "NA";
	}
	myfile.open("IMDB_Top5000-SEECS.csv", ios::in);
	for (int j = 0; j < size; j++)
	{
		string* list = new string[29];
		int count = 0;
		if (j == 0)
			myfile >> line;
		myfile >> line;
		for (int i = 0; i < strlen(line); i++)//SEPERATING THE DATA FROM CSV FILE
		{
			if (line[i] != ',')
				list[count] = list[count] + line[i];
			else
				count++;
		}
		{
			arry[j].index = list[0];
			arry[j].tmovie = list[1];
			arry[j].genres = list[2];
			arry[j].title_year = list[3];
			arry[j].imdb_score = list[4];
			arry[j].num_critic_for_reviews = list[5];
			arry[j].duration = list[6];
			arry[j].gross = list[7];
			arry[j].num_voted_users = list[8];
			arry[j].cast_total_facebook_likes = list[9];
			arry[j].facenumber_in_poster = list[10];
			arry[j].plot_keywords = list[11];
			arry[j].movie_imdb_link = list[12];
			arry[j].num_user_for_reviews = list[13];
			arry[j].language = list[14];
			arry[j].country = list[15];
			arry[j].content_rating = list[16];
			arry[j].budget = list[17];
			arry[j].aspect_ratio = list[18];
			arry[j].movie_facebook_likes = list[19];
			arry[j].color = list[20];
			arry[j].actor1_name = list[21];
			arry[j].actor1_facebook_likes = list[22];
			arry[j].actor2_name = list[23];
			arry[j].actor2_facebook_likes = list[24];
			arry[j].actor3_name = list[25];
			arry[j].actor3_facebook_likes = list[26];
			arry[j].director_name = list[27];
			arry[j].director_facebook_likes = list[28];
			int count_Gen = 0;
			int c_Gen = 0;
			int count_ = 0;
			int cout_ = 0;
			string ge = list[2];
			for (int i = 0; ge[i] != '\0'; i++)
			{
				if (ge[i] == '|')
					count_++;
				cout_++;
			}
			arr[j].index = list[0];
			arr[j].tmovie = list[1];
			int c = 0;
			string word = "";
			for (int x = 0; x < cout_; x++)
			{
				if (ge[x] != '|')
				{
					word = word + ge[x];
				}
				else
				{
					arr[j].Gen[c_Gen++] = word;
					word = "";
				}
			}
			arr[j].Gen[c_Gen] = word;
			arr[j].length = count_ + 1;
			arr[j].title_year = list[3];
			arr[j].imdb_score = list[4];
			arr[j].num_critic_for_reviews = list[5];
			arr[j].duration = list[6];
			arr[j].gross = list[7];
			arr[j].num_voted_users = list[8];
			arr[j].cast_total_facebook_likes = list[9];
			arr[j].facenumber_in_poster = list[10];
			arr[j].plot_keywords = list[11];
			arr[j].movie_imdb_link = list[12];
			arr[j].num_user_for_reviews = list[13];
			arr[j].language = list[14];
			arr[j].country = list[15];
			arr[j].content_rating = list[16];
			arr[j].budget = list[17];
			arr[j].aspect_ratio = list[18];
			arr[j].movie_facebook_likes = list[19];
			arr[j].color = list[20];
			arr[j].actor1_name = list[21];
			arr[j].actor1_facebook_likes = list[22];
			arr[j].actor2_name = list[23];
			arr[j].actor2_facebook_likes = list[24];
			arr[j].actor3_name = list[25];
			arr[j].actor3_facebook_likes = list[26];
			arr[j].director_name = list[27];
			arr[j].director_facebook_likes = list[28];
		}
		obj_Actor->aInsertToTree(list[21], list[22]);
		obj_Actor->aInsertToTree(list[23], list[24]);
		obj_Actor->aInsertToTree(list[25], list[26]);
		obj_Director->dInsertToTree(list[27], list[28]);
	}
	for (int j = 0; j < size; j++)//INSERTING DATA IN MOVIE CLASS
	{
		int index = HashAlgo(stoi(arry[j].index));
		if (index == 0)
			index = 7;
		if (index != 0)
		{
			obj_Movie[index].InsertIntoTable(arry[j], index, obj_Actor, obj_Director);
		}
	}
	cout << endl;
	//call menu
	menu();
	cout << endl;
	cout << endl;
	cout << " Enter Option For the Function to run: "; cin >> option;
	while (option != -1)
	{
		//option = 4;//Pre-defined Option
		switch (option)
		{
		case 1:
			//Function 01
				//Worst Time Complexity For Function 1 
	//For Hash Table first value worst time: O(1)
	//For Tree Treversal worst time: O(n) For BST
	//To Find Any Actor Details 
		{	string aname = "";
		cout << " Enter Name of Actor: "; cin >> aname;
		for (int i = 0; i < size; i++)
		{
			if (arry[i].actor1_name == aname || arry[i].actor2_name == aname || arry[i].actor3_name == aname)
			{
				int index = HashAlgo(stoi(arry[i].index));
				obj_Movie[index].SearchActor(index, aname);
			}
		}
		quickSort(F02, 0, count_Movie - 1);
		for (int i = 0; i < count_Movie; i++)
		{
			cout << " ActorName: " << aname << " ,Movie Title: " << F02[i].data.mtitle <<
				" ,Year: " << F02[i].data.title_year << endl;
		}
		cout << " Actor: " << aname << " acted in " << count_Movie << " movies." << endl; break;
		}
		case 2:
			//Funtion 02
				//Worst Time Complexity For Function 2
	//For Hash Table first value worst time: O(1)
	//For Tree Treversal worst time: O(n) For BST
	//To Find Any CO-Actor of an Actor Searched 
		{
			string aname = "Kevin_Spacey";
			cout << " Enter Name of Actor: "; cin >> aname;
			for (int i = 0; i < size; i++)
			{
				if (arry[i].actor1_name == aname || arry[i].actor2_name == aname || arry[i].actor3_name == aname)
				{
					int index = HashAlgo(stoi(arry[i].index));
					obj_Movie[index].SearchCoActor(index, aname);
				}
			}
			for (int i = 1; i < 8; i++)
			{
				if ((HTable[i].data.actor_1_name_->data.actor_name == aname ||
					HTable[i].data.actor_2_name_->data.actor_name == aname || HTable[i].data.actor_3_name_->data.actor_name == aname))
				{
					cout << " Movie Title: " << HTable[i].data.mtitle
						<< " \nActors: " << HTable[i].data.actor_1_name_->data.actor_name << " \n"
						<< HTable[i].data.actor_2_name_->data.actor_name << " \n"
						<< HTable[i].data.actor_3_name_->data.actor_name << endl;
					cout << endl;
				}
			}
			for (int i = 0; i < count_CoActor; i++)
			{
				cout << " Movie Title: " << F03[i].data.mtitle
					<< " ,\nActors: " << F03[i].data.actor_1_name_->data.actor_name << " \n" << F03[i].data.actor_2_name_->data.actor_name << " \n"
					<< F03[i].data.actor_3_name_->data.actor_name << endl;
				cout << endl;
			}break;
		}
		case 3:
			//Function 03
			//Worst Time Complexity: O(n)
			//Treverses Through the tree and prints all the nodes details
		{
			//Display all the movienodes
			for (int i = 1; i < 8; i++)
				obj_Movie[i].PrintHash(i);
			cout << endl;
			break;
		}
		case 4:
			//Function 04
			//Worst Time: O(n)
			//Looking up for all indexs of array
		{
			//Function 04
			string str1 = "";
			cout << " Enter Name of Actor 1: "; cin >> str1;
			string str2 = "";
			cout << " Enter Name of Actor 2: "; cin >> str2;
			SearchTwoActorsInMovie(arry, str1, str2); break;
		}
		case 5:
			//Worst Time Complexity For Function 5
	//For Hash Table first value worst time: O(1)
	//For Tree Treversal worst time: O(n) For Director BST
    //To find the director details with director name
		{
			//Function 05
			string directorname = "";
			cout << " Enter Name of Director: "; cin >> directorname;
			cout << " List of movies: " << endl;
			for (int i = 1; i < 8; i++)
			{
				if (HTable[i].data.director_name_->data.director_name == directorname)
				{
					cout << " Movie: " << HTable[i].data.mtitle << endl;
				}
				obj_Movie[i].SearchMovieWithDirector(i, directorname);
			}
			break;
		}
		case 6:
			//Searching of Director nodes in linear array using binary search
			//The time complexity of the binary search algorithm is O(log n).
		{
			//Function 06
			string data = "";
			cout << " Enter Genre : "; cin >> data;
			cout << " List of Directors: " << endl;
			PrintDirectorsGenre(data, arr);
			break;
		}
		case 7:
			//Worst Time Complexity For Function 7
	//For Hash Table first value worst time: O(1)
	//For Tree Treversal worst time: O(n) For Director BST
	//To find the movie details with movie name
		{
			//Function 07
			string titlem = "";
			cout << " Enter Name of Movie: "; cin >> titlem;
			int index_ = 0;
			for (int i = 0; i < size; i++)
			{
				if (arr[i].tmovie == titlem)
					index_ = stoi(arr[i].index);
			}
			index_ = HashAlgo(index_);
			if (index_ == 0)
				index_ = 7;
			cout << "Index: " << index_ << endl;
			if (HTable[index_].data.mtitle == titlem)
			{
				cout << " Tilte: " << HTable[index_].data.mtitle << " , Release Year: " << HTable[index_].data.title_year
					<< " , Rating: " << HTable[index_].data.imdb_score << " , Duration: " << HTable[index_].data.duration
					<< "Actors: " << HTable[index_].data.actor_1_name_->data.actor_name << ", " << HTable[index_].data.actor_2_name_->data.actor_name
					<< ", " << HTable[index_].data.actor_3_name_->data.actor_name << ", Director: " <<
					HTable[index_].data.director_name_->data.director_name << endl;
			}
			else
			{
				obj_Movie[index_].SearchByTitle(index_, titlem);
			}
			break;
		}
		case 8:
			//Worst Time Complexity For Function 8 
	//For Hash Table first value worst time: O(1)
	//For Tree Treversal worst time: O(n) For Director BST
	//To find the movie details with year
		{
			string year = "";
			cout << " Enter Name of Year: "; cin >> year;
			cout << " Movies Released in year " << year << ": " << endl;
			for (int i = 1; i < 8; i++)
				obj_Movie[i].SearchByYear(i, year);
			break;
		}
		case 9:
			//Worst Time Complexity For Function 9
			//Using quicksort to sort the array of nodes: O(nlog(n))
			//printing all the data using loop of n=size  
			//To print the movie details sorted yearly
		{
			//Function 9
			int opt;
			cout << " Enter Option For Order:\n 0:Increasing Order\n 1:Decreasing Order\n"; cin >> opt;
			for (int i = 1; i < 8; i++)
				obj_Movie[i].PrintYearWise(i);
			cout << endl;

			quickSort_(F12, 0, size - 1, opt);
			cout << endl;
			cout << " List of Movies Sorted Yearly: " << endl;
			for (int i = 0; i < size; i++)
				cout << "Index " << i + 1 << ": " << F12[i].data.mtitle << "Year: " << F12[i].data.title_year << endl;
			break;
		}
		case 10:
			//Worst Time Complexity For Function 10
			//contructing of array of nodes by tree by using binary search. O(nlogn)
			//Using quicksort to sort the array of nodes: O(nlog(n))
			//printing all the data using loop of n=size  
			//To print the movie details based on genre sorted according to rating score
		{
			//Function 10
			string str1 = "Comedy";
			cout << " Enter Name of Genre: "; cin >> str1;
			PrintMoviesGernes(arr, str1);
			quickSort__(F11, 0, count__ - 1);
			cout << " Movies Sorted According to Rating Based on Genre: " << endl;
			for (int i = 0; i < count__; i++)
			{
				cout << " Movie Name: " << F11[i].tmovie << ", Rating: " << F11[i].imdb_score << endl;
			}
			break;
		}
		case 11:
			//Worst Time Complexity For Function 11
			//Using quicksort to sort the array of nodes: O(nlog(n))
			//printing all the data using loop of n=size  
			//To print the movie details sorted according to rating score
		{	//For Function 11
			for (int i = 1; i < 8; i++)
				obj_Movie[i].PrintMovieRatingWise(i);
			quickSort(F12, 0, size - 1);
			cout << endl;
			for (int i = 0; i < size; i++)
				cout << "Index " << i + 1 << ": " << F12[i].data.mtitle << " Rating: " << F12[i].data.imdb_score << endl;
			break;
		}
		default:
			cout << " Wrong Option...Try Again." << endl;
			break;
		}
		cout << endl;
		cout << endl;
		cout << " Enter Option For the Function to run: "; cin >> option;
		cout << endl;
	}
	cout << " Program Exited." << endl;
	myfile.close();
	return 0;
}