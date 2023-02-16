<?php
/**
 * Copy this file to settings.local.php and use it to make any adjustments you like
 * to your local environment. settings.local.php is Git ignored.
 */

// Prepare a LANDO_INFO constant.
// See: https://jigarius.com/blog/drupal-with-lando
if (isset($_ENV['LANDO_INFO'])) {
  define('LANDO_INFO', json_decode($_ENV['LANDO_INFO'], TRUE));
}

/**
 * PHP error reporting.
 */
error_reporting(E_ALL);
ini_set('display_errors', TRUE);
ini_set('display_startup_errors', TRUE);

/**
 * Allow running database updates at /update.php.
 */
$update_free_access = FALSE;

/**
 * Page cache.
 */
$conf['cache'] = FALSE;

/**
 * Block cache.
 */
$conf['block_cache'] = FALSE;

/**
 * Optimize CSS files.
 */
$conf['preprocess_css'] = FALSE;

/**
 * Optimize JavaScript files.
 */
$conf['preprocess_js'] = FALSE;

/**
 * Turn on HTML comment template suggestions.
 */
$conf['theme_debug'] = TRUE;

/**
 * Database configuration.
 *
 */
if (!isset($databases))
  $databases = array();
// When using lando, use Lando settings.
if (defined('LANDO_INFO')) {
  // Databases.
  $databases['default']['default'] = [
    // Since "mariadb" drivers are the same as "mysql", we hard-code "mysql".
    'driver' => 'mysql',
    'database' => LANDO_INFO['database']['creds']['database'],
    'username' => LANDO_INFO['database']['creds']['user'],
    'password' => LANDO_INFO['database']['creds']['password'],
    'host' => LANDO_INFO['database']['internal_connection']['host'],
    'port' => LANDO_INFO['database']['internal_connection']['port'],
    'prefix' => '',
  ];
}

/**
 * Redis.
 */
// When using lando, use Lando settings.
if (defined('LANDO_INFO')) {
  $conf['redis_client_interface']  = 'PhpRedis';
  $conf['cache_backends'][]        = 'sites/all/modules/redis/redis.autoload.inc';
  $conf['lock_inc']                = 'sites/all/modules/redis/redis.lock.inc';
  $conf['path_inc']                = 'sites/all/modules/redis/redis.path.inc';
  $conf['cache_default_class']     = 'Redis_Cache';
  $conf['cache_prefix']['default'] = 'lando-redis';
  $conf['redis_client_host']       = LANDO_INFO['cache']['internal_connection']['host'];
  $conf['redis_client_port']       = LANDO_INFO['cache']['internal_connection']['port'];
}

/**
 * Set temporary file path.
 */
$conf['file_temporary_path'] = '../tmp';

/**
 * Public file path.
 */
$conf['file_public_path'] = 'sites/default/files';

/**
 * Private file path.
 */
$conf['file_private_path'] = 'sites/default/files/private';
