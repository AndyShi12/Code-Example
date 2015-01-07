//
//  ViewController.swift
//  TableView2
//
//  Created by Andy Shi on 12/31/14.
//  Copyright (c) 2014 Andy Shi. All rights reserved.
//

import UIKit

class ViewController: UIViewController, UITableViewDelegate {

    let array = ["1","2","3","5","66"]
    
    func tableView(tableView: UITableView, numberOfRowsInSection section: Int) -> Int
    {
        return array.count
    }
    
    func tableView(tableView: UITableView, cellForRowAtIndexPath indexPath: NSIndexPath) -> UITableViewCell
    {
        var cell = UITableViewCell(style: UITableViewCellStyle.Default, reuseIdentifier: "cell")
    
        cell.textLabel?.text = array[indexPath.row]
        
        return cell
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

