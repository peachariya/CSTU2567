package exercise1;

public class Game {
    public static void main(String[] args) {
        // สร้างอ็อบเจ็กต์จากคลาส Person
        Person me = new Person();

        // ตั้งค่าชื่อ
        me.setName("AriyaTangrojanakul");

        // ตั้งค่าคะแนน
        me.setScore(10);

        // ย้ายตำแหน่ง
        me.move(10, 50);

        // แสดงผลรายละเอียด
        System.out.println("Name: " + me.getName());
        System.out.println("Score: " + me.getScore());

        // แสดงตำแหน่ง
        me.showPosition();
    }
}
