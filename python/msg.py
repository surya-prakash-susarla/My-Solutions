import plivo

auth_id = "MAOTA1NTHMNGU4YZHIMW"

auth_token = "YmVjNzY2Yjk4ODFlZWM2ZGM2NWZiNzdkOTM4ZjMx"

p = plivo.RestAPI(auth_id,auth_token)

params = {
          
        'dst' : '8885558748',
        'text' : u"Sent with love from python"
        
    }

response = p.send_message(params)


print str(response)

