//
//  ListPlaces.swift
//  RushSwift
//
//  Created by David TEDGUI on 2/13/16.
//  Copyright © 2016 David TEDGUI. All rights reserved.
//

import MapKit

struct PlaceDetails {
    let subtitle: String
    let latitude: Double
    let longitude: Double
	var zoom: Double = 0.3
	let photo: UIImage
    
	init(subtitle: String, latitude: Double, longitude: Double, zoom: Double, photo: String = "city-default") {
        self.subtitle = subtitle
        self.latitude = latitude
        self.longitude = longitude
		self.zoom = zoom
		self.photo = UIImage(named: photo)!
	}
}

struct ListPlaces {
    var places: [String: PlaceDetails] = [
		"Paris": PlaceDetails(subtitle: "The City of Love", latitude: 48.864716, longitude: 2.349014, zoom: 0.2, photo: "city-paris"),
		"San Francisco": PlaceDetails(subtitle: "Silicon Valley", latitude: 37.774929, longitude: -122.419416, zoom: 0.2, photo: "city-sanfran"),
		"New York": PlaceDetails(subtitle: "The Big Apple", latitude: 40.712784, longitude: -74.005941, zoom: 0.2, photo: "city-ny"),
		"London": PlaceDetails(subtitle: "The Old Smoke", latitude: 51.508530, longitude: -0.076132, zoom: 0.2, photo: "city-london"),
		"Barcelona": PlaceDetails(subtitle: "Spain", latitude: 41.390205, longitude: 2.154007, zoom: 0.2, photo: "city-bcn"),
		"Bogota": PlaceDetails(subtitle: "Colombia", latitude: 4.624335, longitude: -74.063644, zoom: 0.2, photo: "city-bog"),
		"Tokyo": PlaceDetails(subtitle: "Japan", latitude: 35.652832, longitude: 139.839478, zoom: 0.3, photo: "city-tokyo"),
        "Tel Aviv": PlaceDetails(subtitle: "The City that Never Sleeps", latitude: 32.109333, longitude: 34.855499, zoom: 0.2, photo: "city-tlv"),
		"42": PlaceDetails(subtitle: "Born to Code", latitude: 48.896684, longitude: 2.318376, zoom: 0.01, photo: "icon-42") ]
	
    
    func returnCities() -> [String] {
        var cities: [String] = []
        
        for (place, _) in places {
            cities.append(place)
        }
        return cities.sort()
    }
    
    func returnPlaceInfo(placeName: String) -> PlaceDetails {
        return places[placeName]!
    }
    
    func returnPlaceCoordinates(placeName: String) -> MKCoordinateRegion {
        let placeInfos = self.places[placeName]!
        
        let placeLocationCoordinate = CLLocationCoordinate2D(latitude: placeInfos.latitude, longitude: placeInfos.longitude)
		let placeCoordinateRegion = MKCoordinateRegion(center: placeLocationCoordinate, span: MKCoordinateSpan(latitudeDelta: placeInfos.zoom, longitudeDelta: placeInfos.zoom))
		
        return placeCoordinateRegion
    }
}