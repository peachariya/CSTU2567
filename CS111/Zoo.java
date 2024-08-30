package interfaceConcepts;

import java.util.ArrayList;

public class Zoo {
	
	private ArrayList<Animal> animals ;
	
	
	public Zoo() {
		animals = new ArrayList<Animal>();
	}
	
	public Zoo(ArrayList<Animal> animals) {
		super();
		this.animals = animals;
	}
		
	
	public void addAnimal(Animal animal) {
		animals.add(animal);
	}
	
	public boolean searchAnimal(Animal ani) {
		for (Animal animal : animals) {
			//
		}
		return true ;
	}
	

	public static void main(String[] args) {

		Lion l1 = new Lion() ; 
		Zebra z1 = new Zebra() ;
		
		Zoo dusitZoo = new Zoo() ;
		
		dusitZoo.addAnimal(z1);
		dusitZoo.addAnimal(l1);
		
		
		for (Animal animal: dusitZoo.getAnimals()) {
			animal.makeSound();
		}
	}

	public  ArrayList<Animal> getAnimals() {
		return animals;
	}

}