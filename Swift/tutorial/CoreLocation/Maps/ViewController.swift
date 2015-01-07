//
//  ViewController.swift
//  Maps
//
//  Created by Andy Shi on 1/7/15.
//  Copyright (c) 2015 Andy Shi. All rights reserved.
//

import UIKit
import MapKit
import CoreLocation

class ViewController: UIViewController, MKMapViewDelegate, CLLocationManagerDelegate {

    @IBOutlet var mapView: MKMapView!
    
    var manager = CLLocationManager()
    
    override func viewDidLoad() {
        
        // Core location
        manager.delegate = self
        manager.desiredAccuracy = kCLLocationAccuracyBest
        manager.requestWhenInUseAuthorization() // only get location when in use
        manager.startUpdatingLocation()
        
        
        super.viewDidLoad()
        // Do any additional setup after loading the view, typically from a nib.
        var latitude: CLLocationDegrees = 41.878876
        var longitude: CLLocationDegrees = -87.635915
        
        var latDel: CLLocationDegrees = 0.01
        var longDel: CLLocationDegrees = 0.01
        var span: MKCoordinateSpan = MKCoordinateSpanMake(latDel, longDel)
        
        var location: CLLocationCoordinate2D = CLLocationCoordinate2DMake(latitude, longitude)
        
        var region:MKCoordinateRegion = MKCoordinateRegionMake(location, span)
        
        mapView.setRegion(region, animated: true)
        
    
        // preset annotation
        var annotation = MKPointAnnotation ()
        annotation.coordinate = location
        annotation.title = "Chicago"
        annotation.subtitle = "Willis Tower"
        mapView.addAnnotation(annotation)
        
        // user annotation
        var longPress =  UILongPressGestureRecognizer(target:self, action: "action:")
        longPress.minimumPressDuration = 2.0
        mapView.addGestureRecognizer(longPress)
    }
    
    
    func action(gestureRec:UIGestureRecognizer) {
        // gather point
        var touchPoint = gestureRec.locationInView(self.mapView)
        // gather coordinate
        var newCoordinate:CLLocationCoordinate2D = mapView.convertPoint(touchPoint, toCoordinateFromView: self.mapView)
        
        var newAnnotation = MKPointAnnotation ()
        newAnnotation.coordinate = newCoordinate
        newAnnotation.title = "Chicago"
        newAnnotation.subtitle = "Chi Town"
        mapView.addAnnotation(newAnnotation)
    }
    
    func locationManager(manager: CLLocationManager!, didUpdateLocations locations: [AnyObject]!) {
        //println("location = \(locations)")
        
        var userLocation: CLLocation = locations[0] as CLLocation
        var latitude: CLLocationDegrees = userLocation.coordinate.latitude
        var longitude: CLLocationDegrees = userLocation.coordinate.longitude
        var latDel: CLLocationDegrees = 0.01
        var longDel: CLLocationDegrees = 0.01
        var span: MKCoordinateSpan = MKCoordinateSpanMake(latDel, longDel)
        
        var location: CLLocationCoordinate2D = CLLocationCoordinate2DMake(latitude, longitude)
        
        var region:MKCoordinateRegion = MKCoordinateRegionMake(location, span)
        
        mapView.setRegion(region, animated: true)
    }
    
    func locationManager(manager: CLLocationManager, didFailWithError error:NSError)
    {
    println(error)
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }


}

