package src;

/* 
*NAME:ARIYA Tangrojanakul
*STDID:6609520108
**/

public class TestToaster {
    public static void main(String[] args) {
        Toaster toaster = new Toaster();
        Bread bread = new Bread();
        toaster.add(bread);
        toaster.toast();
        toaster.getToastState();

        Cookie cookie = new Cookie();
        toaster.add(cookie);
        toaster.toast();
        toaster.getToastState();
    }
}