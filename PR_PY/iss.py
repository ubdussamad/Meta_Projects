#!/usr/bin/python
# -*- coding: latin-1 -*-
from time import strftime, localtime

import requests


session = requests.Session()


class LatLong:

    def __init__(self, latitude, longitude, timestamp):
        self.latitude = float(latitude)
        self.longitude = float(longitude)
        self.time = strftime('%T', localtime(timestamp))

    @property
    def latitude_hemishere(self):
        return 'N' if self.latitude > 0 else 'S'

    @property
    def longitude_hemisphere(self):
        return 'E' if self.longitude > 0 else 'W'

    def __str__(self):
        return (
            "<Latitude: {self.latitude}° {self.latitude_hemishere} |"
            " Longitude: {self.longitude}° {self.longitude_hemisphere} at {self.time}>").format(self=self)

    __repr__ = __str__

    def pprint(self):
        print('International Space Station position @ {}'.format(self.time))
        print('Latitude: {self.latitude}° {self.latitude_hemishere}'.format(self=self))
        print('Longitude: {self.longitude}° {self.longitude_hemisphere}'.format(self=self))


def _get_data_from_api():
    response = session.get('http://api.open-notify.org/iss-now.json')
    response.raise_for_status()
    return response.json()


def get_current_iss_location():
    data = _get_data_from_api()
    iss_position = data['iss_position']
    return LatLong(iss_position['latitude'], iss_position['longitude'], data['timestamp'])


if __name__ == '__main__':
    get_current_iss_location().pprint()
