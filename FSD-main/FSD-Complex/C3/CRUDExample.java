
import java.sql.*;
import java.util.Scanner;

public class CRUDExample {

    static Connection con;
    static Scanner sc = new Scanner(System.in);

    static void connect() throws Exception {
        con = DriverManager.getConnection(
            "jdbc:mysql://localhost:3306/studentdb",
            "root",
            "your_password"
        );
        System.out.println("Connected Successfully");
    }

    // Insert
    static void insert() throws Exception {
        System.out.print("Enter ID, Name, Age: ");
        int id = sc.nextInt();
        String name = sc.next();
        int age = sc.nextInt();

        PreparedStatement ps = con.prepareStatement(
            "INSERT INTO student VALUES (?, ?, ?)");
        ps.setInt(1, id);
        ps.setString(2, name);
        ps.setInt(3, age);
        ps.executeUpdate();

        System.out.println("Record Inserted");
    }

    // Display
    static void display() throws Exception {
        ResultSet rs = con.createStatement().executeQuery(
            "SELECT * FROM student");

        while (rs.next())
            System.out.println(rs.getInt(1) + " " +
                rs.getString(2) + " " + rs.getInt(3));
    }

    // Update
    static void update() throws Exception {
        System.out.print("Enter ID, New Name, New Age: ");
        int id = sc.nextInt();
        String name = sc.next();
        int age = sc.nextInt();

        PreparedStatement ps = con.prepareStatement(
            "UPDATE student SET name=?, age=? WHERE id=?");
        ps.setString(1, name);
        ps.setInt(2, age);
        ps.setInt(3, id);

        System.out.println(ps.executeUpdate() > 0
            ? "Record Updated" : "Record Not Found");
    }

    // Delete
    static void delete() throws Exception {
        System.out.print("Enter ID: ");
        int id = sc.nextInt();

        PreparedStatement ps = con.prepareStatement(
            "DELETE FROM student WHERE id=?");
        ps.setInt(1, id);

        System.out.println(ps.executeUpdate() > 0
            ? "Record Deleted" : "Record Not Found");
    }

    public static void main(String[] args) throws Exception {
        connect();

        while (true) {
            System.out.println("\n1.Insert  2.Display  3.Update  4.Delete  5.Exit");
            System.out.print("Enter Choice: ");
            int ch = sc.nextInt();

            switch (ch) {
                case 1: insert(); break;
                case 2: display(); break;
                case 3: update(); break;
                case 4: delete(); break;
                case 5:
                    con.close();
                    return;
                default:
                    System.out.println("Invalid Choice");
            }
        }
    }
}



// Step 1: Open MySQL Workbench
// 1. Connect to your local MySQL Server.
// 2. Execute the following SQL code (you have already created these, so skip if done):
// CREATE DATABASE studentdb;
// USE studentdb;

// CREATE TABLE student (
//     id INT PRIMARY KEY,
//     name VARCHAR(50),
//     age INT
// );


// Step 2: Open Eclipse
// 1. Open Eclipse IDE.
// 2. Create a project: File → New → Java Project.
// 3. Project name: CRUDProject.
// 4. Click Finish.
// Step 3: Add MySQL Connector
// 1. Right-click CRUDProject → Build Path → Configure Build Path.
// 2. Select Libraries → Classpath → Add External JARs.
// 3. Select the downloaded mysql-connector-j-....jar.
// 4. Click Apply and Close.
// Skip this step if you already added the JAR.
// Step 4: Create Java class
// 1. Right-click src → New → Class.
// 2. Class name: CRUDExample.
// 3. Click Finish.
// 4. Paste the simplified Java program.
// 5. Replace your_password with your MySQL password.
// 6. Press Ctrl + S.
// Step 5: Run the program
// 1. Right-click CRUDExample.java.
// 2. Select Run As → Java Application.
// 3. Use the Eclipse Console.