package src;

/* 
*NAME:ARIYA Tangrojanakul
*STDID:6609520108
**/

import java.util.ArrayList;

public class Toaster implements Toastable {
    private ArrayList<Toastable> item;
    
    public Toaster() {
        item = new ArrayList<>();
    }

    public void add(Toastable item) {
        this.item.add(item);
    }

    public void print() {
        for (Toastable toastable : item) {
            System.out.println(toastable);
        }
    }

    public void toast() {
        for (Toastable toastable : item) {
            toastable.toast();
        }
    }

    public void getToastState() {
        for (Toastable toastable : item) {
            toastable.getToastState();
        }
    }
}