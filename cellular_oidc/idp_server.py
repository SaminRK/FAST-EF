import cherrypy
import jwt
import time
import secrets


codeToInfo = {}


class IdpServer(object):
    @cherrypy.expose('authenticate')
    def GET(self, redirect_uri):
        # The Authorization Server MUST validate the request received as follows:
        #
        # The Authorization Server MUST validate all the OAuth 2.0 parameters according to the OAuth 2.0
        # specification. Verify that a scope parameter is present and contains the openid scope value. (If no openid
        # scope value is present, the request may still be a valid OAuth 2.0 request, but is not an OpenID Connect
        # request.) The Authorization Server MUST verify that all the REQUIRED parameters are present and their usage
        # conforms to this specification. If the sub (subject) Claim is requested with a specific value for the ID
        # Token, the Authorization Server MUST only send a positive response if the End-User identified by that sub
        # value has an active session with the Authorization Server or has been Authenticated as a result of the
        # request. The Authorization Server MUST NOT reply with an ID Token or Access Token for a different user,
        # even if they have an active session with the Authorization Server. Such a request can be made either using
        # an id_token_hint parameter or by requesting a specific Claim Value as described in Section 5.5.1,
        # if the claims parameter is supported by the implementation.
        remote_ip = cherrypy.request.remote.ip
        if remote_ip == '127.0.0.1':  # currently we will take as only local packets as safe, have to check ip address
            # authenticated by core net
            code = secrets.token_urlsafe(10)
            codeToInfo[code] = {
                'redirect_uri': redirect_uri,
                'name': '3202301000025',
            }
            print(redirect_uri)
            path = cherrypy.url('//' + redirect_uri,  "code=" + code, base='')
            print(path)
            raise cherrypy.HTTPRedirect(path, 302)
        raise cherrypy.HTTPError(message=remote_ip)

    @cherrypy.expose('token')
    @cherrypy.tools.json_out()
    def POST(self, grant_type, code, redirect_uri):
        cherrypy.response.headers['Content-type'] = 'application/json'
        cherrypy.response.headers['Cache-control'] = 'no-store'
        cherrypy.response.headers['Pragma'] = 'no-cache'

        auth_time = int(time.time())
        # verify user
        if code in codeToInfo:
            if redirect_uri == codeToInfo[code]['redirect_uri']:
                issue_time = int(time.time())
                exp_time = auth_time + 1000

                id_token = {
                    'iss': cherrypy.request.base,
                    'sub': 'end-user',
                    'aud': 'local-mec-server',
                    'exp': exp_time,
                    'iat': issue_time,
                    'auth_time': auth_time,
                }

                encoded_id_token = jwt.encode(id_token, 'enc_key', 'HS256')

                return {
                    'access-token': 'random',
                    'token-type': 'Bearer',
                    'refresh-token': 'random',
                    'expires-in': 3600,
                    'id-token': encoded_id_token,
                }

        return "sad path"


if __name__ == '__main__':
    cherrypy.quickstart(IdpServer(), '/')
