package exercise1;

public class Game {

    //Main Class
    public static void main(String[] args) {
        //main method
        // Run | Debug
        //create an object from class Person
        Person me = new Person();

        //set my first name as the name of me
        me.setName("ชื่อนักศึกษาของคุณ"); // เปลี่ยนตรงนี้เป็นชื่อนักศึกษาของคุณ

        //set score to 10 for object me
        me.setScore(10);

        //move me to position x = 10, position y = 50
        me.move(10, 50);

        //print detail of object me : name, score
        System.out.println("name: " + me.getName());
        System.out.println("score: " + me.getScore());

        //print position x, position y
        me.showPosition();
    }
}
