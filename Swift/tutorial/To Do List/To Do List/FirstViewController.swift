//
//  FirstViewController.swift
//  To Do List
//
//  Created by Andy Shi on 1/1/15.
//  Copyright (c) 2015 Andy Shi. All rights reserved.
//

import UIKit

var toDoItems:[String] = []

class FirstViewController: UIViewController, UITableViewDelegate, UITableViewDataSource {
    
    
    @IBOutlet var taskTable: UITableView!
    
    
    func tableView(tableView: UITableView, numberOfRowsInSection section: Int) -> Int
    {
        return toDoItems.count
    }
    
    func tableView(tableView: UITableView, cellForRowAtIndexPath indexPath: NSIndexPath) -> UITableViewCell
    {
        var cell = UITableViewCell(style: UITableViewCellStyle.Default, reuseIdentifier: "cell")
        cell.textLabel?.text = toDoItems[indexPath.row]
        return cell
    }
        
    override func viewWillAppear(animated: Bool) {
        
        // load persistant data if available
        if var storedtoDoItems : AnyObject = NSUserDefaults.standardUserDefaults().objectForKey("toDoItems"){
            toDoItems = []
            
            for var i = 0; i < storedtoDoItems.count; i++ {
            toDoItems.append(storedtoDoItems[i] as NSString)
            }
        }
        taskTable.reloadData()
    }
    
    func tableView(tableView: UITableView, commitEditingStyle editingStyle: UITableViewCellEditingStyle, forRowAtIndexPath indexPath: NSIndexPath)
    {
        if (editingStyle == UITableViewCellEditingStyle.Delete)
        {
            toDoItems.removeAtIndex(indexPath.row)
            
            let fixedtoDoItems = toDoItems
            NSUserDefaults.standardUserDefaults().setObject(fixedtoDoItems, forKey: "toDoItems")
            NSUserDefaults.standardUserDefaults().synchronize()
            taskTable.reloadData()
        }
    }
    
    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view, typically from a nib.
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }

}

