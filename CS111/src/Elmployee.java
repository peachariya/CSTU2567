package src;

/* 
*NAME:ARIYA Tangrojanakul
*STDID:6609520108
**/

public class Elmployee {
    protected String fullName;
    protected String department;
    protected int age;
    protected int performanceScore;

    public void setEmployee(String setFullName, int setAge, String setDepartment, int setPerformanceScore) {
        this.fullName = setFullName;
        this.department = setDepartment;
        this.age = setAge;
        this.performanceScore = setPerformanceScore;
    }

    public String getFullName() {
        return this.fullName;
    }

    public String getDepartment() {
        return this.department;
    }

    public int getAge() {
        return this.age;
    }
}