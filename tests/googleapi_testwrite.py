#!/usr/bin/env python
# -*- coding: euc-jp -*- 


##
# @file googleapi_testwrite.py
# @brief 

import array
import json
import gspread
#from oauth2client.client import SignedJwtAssertionCredentials
from oauth2client.service_account import ServiceAccountCredentials
import datetime


def main():

  #doc_id =  '1zfIg5z7F5sbm5BZdUFzeOj9r8TzJjjdOpIc6bAPUyiU'

  #json_key    = json.load(open('shizu-241851f95630.json'))
  json_path = 'iot-summer-c1652295662e.json'
  #doc_id =  '1zds4WRV3CQzSov9ATJrxs454H9UAYwSEquaqH22YBbM'
  #json_key    = json.load(open('newproject-1-6f8d8d9e6dc4.json'))
  #doc_id =  '1bZTdob0RF_Vq1xxyMNN8MmwSk19wW629yS21XJ2M4YA'
  doc_id =  '12m8fQQBRNKPEzKOjilJldZKlam7jf5BlCp7ZazNkVvU'
  #json_key    = json.load(open('iot-seminar-project-6d833cb23f4b.json'))
  scope       = ['https://spreadsheets.google.com/feeds']
  #print json_key['client_email']
  #credentials = SignedJwtAssertionCredentials(
  #                json_key['client_email'], 
  #                json_key['private_key'].encode(), 
  #                scope)
  credentials =  ServiceAccountCredentials.from_json_keyfile_name(
                  json_path,scope)

  gclient = gspread.authorize(credentials)
  gfile   = gclient.open_by_key(doc_id)
  wsheet  = gfile.get_worksheet(0)

  tdatetime = datetime.datetime.now()
  data =  []
  data.append((tdatetime-datetime.datetime(1899, 12, 30)).days)
  tdelta = tdatetime - datetime.datetime.strptime("0:0:0.0", "%H:%M:%S.%f")
  data.append((tdelta.seconds+(tdelta.microseconds/1000000))/(60.0*60.0*24.0))
  data.append(9);
  data.append(10);
  data.append(11);
  data.append(12);
  data.append(13);
  data.append(14);
  data.append(15);
  data.append(16);
  wsheet.append_row(data)

  records = wsheet.get_all_records()
  #print records

if __name__ == '__main__':
  main()
