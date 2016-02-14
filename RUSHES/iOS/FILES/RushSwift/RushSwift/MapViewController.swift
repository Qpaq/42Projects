//
//  FirstViewController.swift
//  RushSwift
//
//  Created by David TEDGUI on 2/13/16.
//  Copyright © 2016 David TEDGUI. All rights reserved.
//

import UIKit
import MapKit
import CoreLocation

var mainViewBool: Int = 0

class MapViewController: UIViewController, MKMapViewDelegate, CLLocationManagerDelegate {

    @IBOutlet weak var mapView: MKMapView!
    @IBOutlet weak var changeMapStateSegmentedControl: UISegmentedControl!
    @IBOutlet weak var getCurrentLocationIcon: UIButton!
    
    let locationManager = CLLocationManager()
	
	var currentMapType: MKMapType = .Satellite
	var showLocation = "42"
	
	override func viewDidLoad() {
        super.viewDidLoad()
		
        self.mapView.delegate = self
        self.locationManager.delegate = self
		
		mapView.mapType = currentMapType
		if mainViewBool == 0 {
			setAllAnnotations()
			mainViewBool = 1
		}

		centerMapOnPlace(showLocation)
    }
	
	override func viewWillAppear(animated: Bool) {
		mapView.mapType = currentMapType
		switch currentMapType {
			case MKMapType.Standard: changeMapStateSegmentedControl.selectedSegmentIndex = 0
			case MKMapType.Satellite: changeMapStateSegmentedControl.selectedSegmentIndex = 1
			case MKMapType.Hybrid: changeMapStateSegmentedControl.selectedSegmentIndex = 2
			default: changeMapStateSegmentedControl.selectedSegmentIndex = 0
		}
	}

	
    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
    }
	

	// CHANGE MAP TYPE
    @IBAction func changeMapState(sender: AnyObject) {
        switch sender.selectedSegmentIndex {
            case 0:
				currentMapType = .Standard
            case 1:
				currentMapType = .Satellite
            case 2:
				currentMapType = .Hybrid
            default:
				currentMapType = .Satellite
        }
		mapView.mapType = currentMapType
    }
	
	
	// USER LOCATION
    @IBAction func getUserCurrentLocation(sender: AnyObject) {
        self.locationManager.requestWhenInUseAuthorization()
        self.locationManager.startUpdatingLocation()
        self.mapView.showsUserLocation = true
		getCurrentLocationIcon.setImage(UIImage(named: "geolocation-active"), forState: UIControlState.Normal)
    }
    func locationManager(manager: CLLocationManager, didUpdateLocations locations: [CLLocation]) {
        let location = locations.last
        let center = CLLocationCoordinate2D(latitude: location!.coordinate.latitude, longitude: location!.coordinate.longitude)
        let region = MKCoordinateRegion(center: center, span: MKCoordinateSpan(latitudeDelta: 0.07, longitudeDelta: 0.07))
        self.mapView.setRegion(region, animated: true)
        self.locationManager.stopUpdatingLocation()
    }
    func locationManager(manager: CLLocationManager, didFailWithError error: NSError) {
        print("Error: " + error.localizedDescription)
    }
    
    // PUT PLACE ON MAP
    func addAnnotationToPlace(placeName: String) {
        let placeInfos = ListPlaces().returnPlaceInfo(placeName)
        
        let placeAnnotation = MKPointAnnotation()
        placeAnnotation.coordinate = CLLocationCoordinate2D(latitude: placeInfos.latitude, longitude: placeInfos.longitude)
        placeAnnotation.title = placeName
        placeAnnotation.subtitle = placeInfos.subtitle
        mapView.addAnnotation(placeAnnotation)
		mapView.selectAnnotation(placeAnnotation, animated: true)
    }
    
    func centerMapOnPlace(placeName: String) {
        let placeCoordinates = ListPlaces().returnPlaceCoordinates(placeName)
        mapView.setRegion(placeCoordinates, animated: true)
        addAnnotationToPlace(placeName)
    }
	
	func setAllAnnotations() {
		let cities = ListPlaces().returnCities()
		for city in cities {
			if city != "42" {
				addAnnotationToPlace(city)
			}
		}
	}
	
}
