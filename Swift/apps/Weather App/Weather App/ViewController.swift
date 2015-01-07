//
//  ViewController.swift
//  Weather App
//
//  Created by Andy Shi on 1/2/15.
//  Copyright (c) 2015 Andy Shi. All rights reserved.
//

import UIKit

class ViewController: UIViewController {

    @IBOutlet var city: UITextField!
    @IBOutlet var weather: UILabel!
    
    @IBAction func search(sender: AnyObject) {
        
        var urlString = "http://www.weather-forecast.com/locations/" + city.text.stringByReplacingOccurrencesOfString(" ", withString: "") + "/forecasts/latest"
        
        var url = NSURL(string: urlString)
        
        let task = NSURLSession.sharedSession().dataTaskWithURL(url!) {
            (data, response, error) in
            
            var urlContent = NSString(data: data, encoding: NSUTF8StringEncoding)
            
            if urlContent!.containsString("<span class=\"phrase\">") {
                
                var contentArray = urlContent!.componentsSeparatedByString("<span class=\"phrase\">")
                var newContentArray = contentArray[1].componentsSeparatedByString("</span>")
                var weatherForcast = newContentArray[0].stringByReplacingOccurrencesOfString("&deg;", withString: "º")
                
                dispatch_async(dispatch_get_main_queue()) {
                    self.weather.text = weatherForcast
                }
            } else {
                
                dispatch_async(dispatch_get_main_queue()) {
                    
                    self.weather.text = "Could not find that city - please try again"
                }
            }
        }
        task.resume()

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

