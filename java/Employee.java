package p1;

 public abstract class Employee {
	 int id;
	 String name;
	 double salary;



	 public void setid(int id)
	 {
	 this.id=id;
	 }
	 int getid()
	 {
	 return this.id;
	 }

	 public void setname(String name)
	 {
	 this.name=name;
	 }
	  String getname()
	 {
	 return this.name;
	 }

	  public void setsalary(double salary)
	 {
	 this.salary=salary;
	 }
	 double getsalary()
	 {
	 return this.salary;
	 }


	 //constructor start
	public Employee()
	 {
	 this.id=101;
	 this.name="shambhu";
	 this.salary=30000;
	 }

	public Employee(int i,String n,double s)
	 {
	 this.id=i;
	 this.name=n;
	 this.salary=s;
	 }
	 //constructor ends
	public  void display()
	 {
	 	System.out.println("id:"+this.id);
	 	System.out.println("name:"+this.name);
	 	System.out.println("salary:"+this.salary);
	 }
	 

}
