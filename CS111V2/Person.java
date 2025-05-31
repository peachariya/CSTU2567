package exercise1;

public class Person {
	//Data Abstraction for Class Person in Game
	//name type String
	private String name ;
	//score type integer
	private  int score ;
	//positionX type integer
	//positionY type integer
	private int positionX, positionY ;

	//Function Abstraction of Class Person
	//setName() : change name of Person
	public void setName(String newName) {
		name =  newName ;
	}
	//getName() : return name of Person
    public String getName() {
    	return name ;
    }
	//setScore() : change score of Person
	public void setScore(int newScore) {
		score = newScore ;
	}
	//getScore() : return score of Person
	public int getScore() {
		return score ;
	}

	//move() : set new position x and position y of Person
	public void move(int x1, int y1) {
		positionX = x1 ;
		positionY = y1 ;
	}
	//showPosition() : print current position x and position y 
	//of Person to console. 
	
	public void showPosition() {
		System.out.println("Position X: " + positionX) ;
		System.out.println("Position Y: " + positionY) ;
	}
	
}
