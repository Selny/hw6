#include <iostream>

using namespace std;

class Ingredient {
protected:
	string name;
	double fats;
	double protein;
	double carbohydrates;
	int kcal;
public:
	//constructor default ,parametric

	Ingredient() = default;
	Ingredient(const string name, const double fats, const double protein, const double carbohydrates, const int kcal) {
		SetName(name);
		SetFats(fats);
		SetProtein(protein);
		SetCarbohydrates(carbohydrates);
		SetKcal(kcal);
	} 

	//getter setter
	
	string GetName() { return name; }
	double GetFats() { return fats; }
	double GetProtein() { return protein; }
	double GetCarbohydrates() { return carbohydrates; }
	int GetKcal() { return kcal; }

	void SetName(const string name) { this->name = name; }
	void SetFats(const double fats) { this->fats = fats; }
	void SetProtein(const double protein) { this->protein = protein; }
	void SetCarbohydrates(const double carbohydrates) { this->carbohydrates = carbohydrates; }
	void SetKcal(const int kcal) { this->kcal = kcal;}

	//pure virtual destructor - > class should be abstract

	virtual ~Ingredient() = 0;

};

class Mushrooms :public Ingredient {
	string color;
public:
	Mushrooms(const string name, const double fat,const double protein, const double carbohydrates, const int kcal, const string color) : Ingredient(name, fat, protein, carbohydrates, kcal) {
		SetName(name);
		SetFats(fats);
		SetProtein(protein);
		SetCarbohydrates(carbohydrates);
		SetKcal(kcal);
		SetColor(color);
	}

	string GetColor() { return color; }

	void SetColor(const string color) { this->color = color; }

};

class Meat :public Ingredient {
	string type;
public:
	Meat(const string name, const double fat,const double protein, const double carbohydrates, const int kcal, const string type) : Ingredient(name, fat, protein, carbohydrates, kcal) {
		SetName(name);
		SetFats(fats);
		SetProtein(protein);
		SetCarbohydrates(carbohydrates);
		SetKcal(kcal);
		SetType(type);
	}

	string GetType() { return type; }

	void SetType(const string type) { this->type = type; }	
};

class Spices :public Ingredient {
	int scoville;
public:
		Spices(const string name, const double fat,const double protein, const double carbohydrates, const int kcal, const int scoville) : Ingredient(name, fat, protein, carbohydrates, kcal) {
			SetName(name);
			SetFats(fats);
			SetProtein(protein);
			SetCarbohydrates(carbohydrates);
			SetKcal(kcal);
			SetScoville(scoville);
		}

		int GetScoville() { return scoville; }

		void SetScoville(const int scoville) { this->scoville = scoville;}

};

class Cheese :public Ingredient {
	int oldness;
public:
	Cheese(const string name, const double fat,const double protein, const double carbohydrates, const int kcal, const int olndess) : Ingredient(name, fat, protein, carbohydrates, kcal) {
		SetName(name);
		SetFats(fats);
		SetProtein(protein);
		SetCarbohydrates(carbohydrates);
		SetKcal(kcal);
		SetOldness(oldness);
	}

	int GetOldness() { return oldness; }

	void SetOldness(const int oldness) { this->oldness = oldness; }
};

class Tomatoes :public Ingredient {
	string region;
public:
	Tomatoes(const string name, const double fat,const double protein, const double carbohydrates, const int kcal, const string region) : Ingredient(name, fat, protein, carbohydrates, kcal) {
		SetName(name);
		SetFats(fats);
		SetProtein(protein);
		SetCarbohydrates(carbohydrates);
		SetKcal(kcal);
		SetRegion(region);
	}

	string GetRegion() { return region; }

	void SetRegion(const string region) { this->region = region; }
};


struct RecipetItem {
	Ingredient* ingredient; //one object
	int amount;
	//constructor
    RecipetItem(const Ingredient* ingredient, const int amount) {
        this->ingredient = ingredient;
        this->amount = amount;
    }
};

//Yemek
class Dish { // Meal
protected:
	RecipetItem** ingredients;
	int count;
	string name;
public:
	//ctor Default + Parametric
	
	Dish() = default;

	Dish(const RecipetItem** ingredients, const int count, const string name) {
        RecipetItem* ingredient = new RecipetItem[count];
        this->name = name;
        
	}

	//abstract class , with pure virtual destructor

	//getter setter

	void addIngredient(Ingredient* ingredient, int amount) {
		ingredient[count++] = ingredient;
	}

	virtual void taste() {
		cout << "I do not know what is this ? " << endl;
	}

	virtual void printRecipe() const {
        for (int i = 0; i < count; i++)
        cout << ingredient[i] << endl;
	}
	virtual ~Dish() = 0;
};


class Pizza :public Dish {
    int cheese_amount;
public:
    Pizza() = default;
    Pizza(const RecipetItem** ingredients, const int count, const string name, const int cheese_amount) : Pizza(ingredients, count, name){
        this->cheese_amount=cheese_amount;
    }
    void say() { cout << "Nom nom, doydum" << endl; }
};


class Kabab :public Dish {
    bool isKababInTheSish;
public:
    Kabab() = default;
    Kabab(const RecipetItem** ingredients, const int count, const string name, const bool isKababInTheSish) : Kabab(ingredients, count, name){
        this->isKababInTheSish=isKababInTheSish;
    }
    
    if(isKababInTheSish) { cout << "Kabab shishde tutub dishde" << endl; }
};

class Dolma :public Dish {
    string yarpaq_type;
public:
    Dolma() = default;
    Dolma(const RecipetItem** ingredients, const int count, const string name, const bool yarpaq_type) : Dolma(ingredients, count, name){
        this->yarpaq_type=yarpaq_type;
    }
    void buk() { cout << "dolma is bukuling" << endl; }
};


class CookingDevice {
protected:
	Dish* dish;
	bool isCooked;
	int second;
	virtual void cook() {
        cout << "beep beep, gel gotur" << endl;
	}
};

class Oven :public CookingDevice {
public:

	Oven()
	{
		dish = new Pizza("Bomba Pizza");
	}
};

class Pot :public CookingDevice {

public:
	Pot()
	{
		dish = new Dolma("Dolma");
	}

};

class Brazier :public CookingDevice {

public:
	Brazier()
	{
		dish = new Kabab("Babat Kabab");
	}

};

int main() {

    //Muellim tapsirilqarim coxdu deye, tez-tez prottypelarin ve iclerini doldurmaqa calisiram 🤷
    
    return 0;
}
