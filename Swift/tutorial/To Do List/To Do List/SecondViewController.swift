//
//  SecondViewController.swift
//  To Do List
//
//  Created by Andy Shi on 1/1/15.
//  Copyright (c) 2015 Andy Shi. All rights reserved.
//

import UIKit

class SecondViewController: UIViewController, UITextFieldDelegate {

    
    @IBOutlet var toDo: UITextField!
    
    @IBAction func addItem(sender: AnyObject) {
        toDoItems.append(toDo.text)
        
        // immutable
        let fixedtoDoItems = toDoItems
        NSUserDefaults.standardUserDefaults().setObject(fixedtoDoItems, forKey: "toDoItems")
        NSUserDefaults.standardUserDefaults().synchronize()
        
        //var storedtoDoItems : AnyObject! = NSUserDefaults.standardUserDefaults().objectForKey("toDoItems")
        //println(storedtoDoItems)
        self.view.endEditing(true)

    }
    
    func textFieldShouldReturn(textField: UITextField) -> Bool {
        textField.resignFirstResponder()
        return true
    }
    
    //override func touchesBegan(touches: NSSet, withEvent event: UIEvent) {
       // self.view.endEditing(true)
    //}

    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view, typically from a nib.
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }


}

