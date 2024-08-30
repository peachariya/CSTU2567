package src;

/* 
*NAME:ARIYA Tangrojanakul
*STDID:6609520108
**/

public class Cookie implements Toastable {
    public static final String BURNT = "Burn";
    public static final String CRISP = "Crisp";
    public static final String SOFT = "Soft";
    private String state;

    public Cookie() {
        state = SOFT;
    }
    public void setState(String state) {
        this.state = state;
    }

    public String getState() {
        return state;
    }

    public String toString() {
        return "Cookie is now: " + state;
    }

    public void toast() {
        if (state.equals(SOFT)) {
            state = CRISP;
        } else if (state.equals(CRISP)) {
            state = BURNT;
        }
    }
    public void getToastState() {
        System.out.println("Cookie is now: " + state);
    }
}